//
// Created by Mike on 18-11-2021.
//

#include "PhysicsImpl.hpp"

using namespace Engine;

const float PPM = 21.0f;

PhysicsImpl::PhysicsImpl() : _world{b2World{b2Vec2{0.0f, 10.0f}}}, _collision{std::make_unique<CollisionManager>()} {

}

void PhysicsImpl::CreateBody(RigidBody &rigidBody, Transform &transform) {
    b2BodyDef bodyDef;
    float width = 21 * transform.scaleWidth;
    float height = 21 * transform.scaleHeight;

    bodyDef.position.Set(transform.position.x / PPM, transform.position.y / PPM);

    switch (rigidBody.bodyType) {
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
    RigidBody *pointerToRigidBody = &rigidBody;
    b2Body *box2dRigidBody = _world.CreateBody(&bodyDef);
    box2dRigidBody->SetUserData(pointerToRigidBody);

    b2PolygonShape collisionShape;
    collisionShape.SetAsBox(width / 2 / PPM, height/ 2 / PPM);


    if (rigidBody.bodyType != BodyType::STATIC) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        box2dRigidBody->CreateFixture(&fixtureDef);
    } else {
        box2dRigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::DestroyWorld() {

}

void PhysicsImpl::DestroyBody(b2Body *body) {

}

void PhysicsImpl::Update(RigidBody &rigidBody, Transform &transform) {
    for (b2Body *body = _world.GetBodyList(); body; body = body->GetNext()) {
        RigidBody *pointerToRigidBody = &rigidBody;
        if (body->GetUserData() == pointerToRigidBody) {
            transform.position.x = body->GetPosition().x * PPM;
            transform.position.y = body->GetPosition().y * PPM;
        }
    }
}

void PhysicsImpl::Step() {
    _world.Step(1.0f / 60.0f, 8, 6);
}
