#include "PhysicsImpl.hpp"
#include <cmath>

using namespace Engine;

const float PPM = 21.0f;

PhysicsImpl::PhysicsImpl() {
    ResetForNextScene();
}

void PhysicsImpl::CreateBody(const GameObject& gameObject) {
    float width = 21 * gameObject.transform.scaleWidth;
    float height = 21 * gameObject.transform.scaleHeight;

    // Making the box2d rigidbody
    b2BodyDef bodyDef;
    bodyDef.position.Set(gameObject.transform.position.x / PPM, gameObject.transform.position.y / PPM);
    switch (gameObject.rigidBody.bodyType) {
        case BodyType::STATIC:
            bodyDef.type = b2_staticBody;
            break;
        case BodyType::DYNAMIC:
            bodyDef.type = b2_dynamicBody;
            break;
        case BodyType::KINEMATIC:
            bodyDef.type = b2_kinematicBody;
            break;
    }
    b2Body *box2dRigidBody = _world->CreateBody(&bodyDef);
    box2dRigidBody->SetGravityScale(gameObject.rigidBody.gravityScale);
    box2dRigidBody->SetUserData((void*)&gameObject);

    // Attaching collider
    try {
        if (gameObject.collider.active) {
            if(gameObject.collider.type == ColliderType::BOX_COLLIDER) {
                double density = gameObject.rigidBody.mass / ((width / PPM) * (width / PPM));
                AttachBoxCollider(box2dRigidBody, gameObject.collider.GetData().at(0), gameObject.collider.GetData().at(1), density);
            } else if (gameObject.collider.type == ColliderType::CIRCLE_COLLIDER){
                double radius  = gameObject.collider.GetData().at(0);
                double density = gameObject.rigidBody.mass / (M_PI * (radius / PPM * radius / PPM));
                AttachCircleCollider(box2dRigidBody, radius, density);
            }
        }
    } catch (const std::exception& error) {
        std::string message { error.what() };
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s", (message+"Couldn't construct collider: ").c_str());
    }
}

void PhysicsImpl::AttachBoxCollider(b2Body* rigidBody, double width, double height, double density) {
    b2PolygonShape collisionShape;
    collisionShape.SetAsBox(width / 2 / PPM, height / 2 / PPM);
    if (rigidBody->GetType() != b2_staticBody) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = density;
        fixtureDef.friction = 1.0f;
        rigidBody->SetLinearDamping(1.0f);

        rigidBody->CreateFixture(&fixtureDef);
    } else {
        rigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::AttachCircleCollider(b2Body* rigidBody, double radius, double density) {
    b2CircleShape collisionShape;
    collisionShape.m_radius = radius / PPM;

    if (rigidBody->GetType() != b2_staticBody) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = density;
//        fixtureDef.friction = 1.0f;
        rigidBody->SetLinearDamping(2.0f);
        rigidBody->CreateFixture(&fixtureDef);
    } else {
        rigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::PerformPhysicsCalculationsForFrame() {
    _contactListener->flushForNextFrame();
    _world->Step(1.0f / 60.0f, 8, 6);
}

void PhysicsImpl::UpdateGameObjectStateFromPhysicsTick(GameObject& gameObject) {
    for (b2Body* body = _world->GetBodyList(); body; body = body->GetNext()) {
        if (body->GetUserData() == &gameObject) {

            b2Vec2 force = {gameObject.rigidBody.forceX / PPM, gameObject.rigidBody.forceY * -1 / PPM};
            b2Vec2 pos = body->GetPosition();

            body->ApplyLinearImpulse(force, pos, true);

            gameObject.rigidBody.forceY = 0;
            gameObject.rigidBody.forceX = 0;

            gameObject.transform.position.x = body->GetPosition().x * PPM;
            gameObject.transform.position.y = body->GetPosition().y * PPM;
        }
    }
}

void PhysicsImpl::runCollisionScripts() {
    _contactListener->runCollisionScripts();
}

void PhysicsImpl::ResetForNextScene() {
    _world = std::make_unique<b2World>(b2Vec2{0.0f, 10.0f});
    _contactListener = std::make_unique<ContactListener>();
    _world->SetContactListener(_contactListener.get());
}
