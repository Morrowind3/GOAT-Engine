#include "PhysicsImpl.hpp"
#include <cmath>

using namespace Engine;

const float PPM = 21.0f;

PhysicsImpl::PhysicsImpl() {
    resetForNextScene();
}

void PhysicsImpl::createBody(const GameObject& gameObject) {
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
                attachBoxCollider(box2dRigidBody, gameObject.collider.getData().at(0),
                                  gameObject.collider.getData().at(1), density);
            } else if (gameObject.collider.type == ColliderType::CIRCLE_COLLIDER){
                double radius  = gameObject.collider.getData().at(0);
                double density = gameObject.rigidBody.mass / (M_PI * (radius / PPM * radius / PPM));
                attachCircleCollider(box2dRigidBody, radius, density);
            }
        }
    } catch (const std::exception& error) {
        std::string message { error.what() };
        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "%s", (message+"Couldn't construct collider: ").c_str());
    }
}

void PhysicsImpl::attachBoxCollider(b2Body* rigidBody, double width, double height, double density) {
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

void PhysicsImpl::attachCircleCollider(b2Body* rigidBody, double radius, double density) {
    b2CircleShape collisionShape;
    collisionShape.m_radius = radius / PPM;

    if (rigidBody->GetType() != b2_staticBody) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = density;
        rigidBody->SetLinearDamping(1.0f);
        rigidBody->CreateFixture(&fixtureDef);
    } else {
        rigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::performPhysicsCalculationsForFrame(const double deltaTimeInMs) {
    _contactListener->flushForNextFrame();
    _world->Step(1.0f / deltaTimeInMs/3.0f , 8, 6);
    // Erase inactive bodies
    for (b2Body* body = _world->GetBodyList(); body; body = body->GetNext()) {
        auto* object = (GameObject*)body->GetUserData();
        if (!object->active || !object->rigidBody.active) {
            _world->DestroyBody(body);
        }
    }
}

void PhysicsImpl::updateGameObjectStateFromPhysicsTick(GameObject& gameObject) {
    bool found {false};

    for (b2Body* body = _world->GetBodyList(); body; body = body->GetNext()) {
        if (body->GetUserData() == &gameObject) {
            found = true;

            b2Vec2 force = {gameObject.rigidBody.forceX / PPM, gameObject.rigidBody.forceY * -1 / PPM};
            b2Vec2 pos = body->GetPosition();

            body->ApplyLinearImpulse(force, pos, true);

            gameObject.rigidBody.forceY = 0;
            gameObject.rigidBody.forceX = 0;

            gameObject.transform.position.x = body->GetPosition().x * PPM;
            gameObject.transform.position.y = body->GetPosition().y * PPM;
        }
    }

    if(!found) {
        createBody(gameObject);
    }
}

void PhysicsImpl::runCollisionScripts() {
    _contactListener->runCollisionScripts();
}

void PhysicsImpl::resetForNextScene() {
    _world = std::make_unique<b2World>(b2Vec2{0.0f, 10.0f});
    _contactListener = std::make_unique<ContactListener>();
    _world->SetContactListener(_contactListener.get());
}
