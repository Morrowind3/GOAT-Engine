#include "PhysicsImpl.hpp"
#include <cmath>

using namespace Engine;

const float PPM = 21.0f;

PhysicsImpl::PhysicsImpl() {
    resetForNextScene();
}

void PhysicsImpl::createBody(const GameObject &gameObject) {
    float width = PPM * gameObject.transform.scaleWidth;
    float height = PPM * gameObject.transform.scaleHeight;

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
    box2dRigidBody->SetFixedRotation(true);
    box2dRigidBody->SetGravityScale(gameObject.rigidBody.gravityScale);
    box2dRigidBody->SetUserData((void *) &gameObject);
    box2dRigidBody->SetLinearDamping(1.25f);
    box2dRigidBody->SetAngularDamping(1.0f);

    // Attaching collider
    try {
        if (gameObject.collider.active) {
            double density, radius, friction, restitution;
            b2Vec2 offSet;
            switch (gameObject.collider.type) {
                case ColliderType::NONE:
                    break;
                case ColliderType::BOX_COLLIDER:
                    friction = gameObject.collider.getData().at(2);
                    density = gameObject.rigidBody.mass / ((width / PPM) * (height / PPM));
                    restitution = gameObject.collider.getData().at(3);
                    attachBoxCollider(box2dRigidBody, gameObject.collider.getData().at(0),
                                      gameObject.collider.getData().at(1), density, false, friction, restitution);
                    break;
                case ColliderType::BOX_SENSOR:
                    friction = gameObject.collider.getData().at(2);
                    restitution = gameObject.collider.getData().at(3);
                    attachBoxCollider(box2dRigidBody, gameObject.collider.getData().at(0),
                                      gameObject.collider.getData().at(1), 0, true, friction, restitution);
                    break;
                case ColliderType::CIRCLE_COLLIDER:
                    radius = gameObject.collider.getData().at(0);
                    density = gameObject.rigidBody.mass / (M_PI * ((radius / PPM) * (radius / PPM)));
                    friction = gameObject.collider.getData().at(3);
                    restitution = gameObject.collider.getData().at(4);
                    offSet = b2Vec2(gameObject.collider.getData().at(1), gameObject.collider.getData().at(2));
                    attachCircleCollider(box2dRigidBody, radius, density, false, offSet, friction, restitution);
                    break;
                case ColliderType::CIRCLE_SENSOR:
                    friction = gameObject.collider.getData().at(3);
                    radius = gameObject.collider.getData().at(0);
                    restitution = gameObject.collider.getData().at(4);
                    offSet = b2Vec2(gameObject.collider.getData().at(1), gameObject.collider.getData().at(2));
                    attachCircleCollider(box2dRigidBody, radius, 0, true, offSet, friction, restitution);
                    break;
                case ColliderType::OVAL_COLLIDER:
                    radius = gameObject.collider.getData().at(0);
                    friction = gameObject.collider.getData().at(3);
                    restitution = gameObject.collider.getData().at(4);
                    offSet = b2Vec2(gameObject.collider.getData().at(1), gameObject.collider.getData().at(2));
                    density = gameObject.rigidBody.mass / (M_PI * ((radius / PPM) * (radius / PPM)));
                    attachOvalCollider(box2dRigidBody, radius, density, offSet, friction, restitution);
                    break;
            }
        }
    } catch (const std::exception& error) {
        std::string message { error.what() };
        _debug.log("Couldn't construct collider: " + message);
    }
}

void PhysicsImpl::attachBoxCollider(b2Body *rigidBody, double width, double height, double density, bool isSensor, double friction,  double restitution) {
    b2PolygonShape collisionShape;
    collisionShape.SetAsBox(width / 2 / PPM, height / 2 / PPM);
    if (isSensor) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.isSensor = isSensor;
        rigidBody->CreateFixture(&fixtureDef);
    } else if (rigidBody->GetType() != b2_staticBody) {
        b2FixtureDef fixtureDef;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.shape = &collisionShape;
        fixtureDef.restitution = restitution;
        rigidBody->CreateFixture(&fixtureDef);
    } else {
        b2FixtureDef staticDef;
        staticDef.density = 0.0f;
        staticDef.friction = friction;
        staticDef.shape = &collisionShape;
        rigidBody->CreateFixture(&staticDef);
    }
}


void PhysicsImpl::attachCircleCollider(b2Body *rigidBody, double radius, double density, bool isSensor, b2Vec2 offset, double friction,  double restitution) {
    b2CircleShape collisionShape;
    collisionShape.m_radius = radius / PPM;
    collisionShape.m_p = offset;
    if (isSensor) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.isSensor = isSensor;
        rigidBody->CreateFixture(&fixtureDef);
    } else if (rigidBody->GetType() != b2_staticBody) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution = restitution;
        rigidBody->CreateFixture(&fixtureDef);
    } else {
        rigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::attachOvalCollider(b2Body *rigidBody, double radius, double density, b2Vec2 offSet, double friction, double restitution ) {
    // Feet collision shape
    b2CircleShape feetCollisionShape;
    feetCollisionShape.m_radius = radius / PPM;
    feetCollisionShape.m_p = offSet;
    b2FixtureDef feetDef;
    feetDef.shape = &feetCollisionShape;
    feetDef.density = density;
    feetDef.friction = friction;
    feetDef.restitution = restitution;
    rigidBody->CreateFixture(&feetDef);

    // Head collision shape
    b2CircleShape headCollisionShape;
    headCollisionShape.m_radius = radius / PPM;
    headCollisionShape.m_p = b2Vec2(0.0f, offSet.y * -1);
    b2FixtureDef headDef;
    headDef.shape = &headCollisionShape;
    headDef.density = 0;
    headDef.friction = friction;
    rigidBody->CreateFixture(&headDef);
}

void PhysicsImpl::performPhysicsCalculationsForFrame(const double deltaTimeInMs) {
    _contactListener->flushForNextFrame();
    _world->Step(_engineCalls.speed() / 50.0f, 8 * _engineCalls.speed(), 6 * _engineCalls.speed());
    // Erase inactive bodies
    for (b2Body *body = _world->GetBodyList(); body; body = body->GetNext()) {
        auto *object = (GameObject *) body->GetUserData();
        if (!object->active || !object->rigidBody.active) {
            _world->DestroyBody(body);
        }
    }
}

void PhysicsImpl::updateGameObjectStateFromPhysicsTick(GameObject &gameObject) {
    bool found{false};

    for (b2Body *body = _world->GetBodyList(); body; body = body->GetNext()) {
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

    if (!found) {
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
