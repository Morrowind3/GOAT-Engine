//
// Created by Mike on 18-11-2021.
//

#include "PhysicsImpl.hpp"
#include "math.h"

using namespace Engine;

const float PPM = 21.0f;

PhysicsImpl::PhysicsImpl() : _world{b2World{b2Vec2{0.0f, 10.0f}}}, _collision{std::make_unique<CollisionManager>()} {

}

void PhysicsImpl::CreateBody(std::shared_ptr<GameObject> gameObject) {
    float width = 21 * gameObject.get()->transform.scaleWidth;
    float height = 21 * gameObject.get()->transform.scaleHeight;

    // Making the box2d rigidbody
    b2BodyDef bodyDef;
    bodyDef.position.Set(gameObject.get()->transform.position.x / PPM, gameObject.get()->transform.position.y / PPM);
    switch (gameObject.get()->rigidBody.bodyType) {
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
    b2Body *box2dRigidBody = _world.CreateBody(&bodyDef);
    box2dRigidBody->SetGravityScale(gameObject.get()->rigidBody.gravityScale);
    box2dRigidBody->SetUserData(gameObject.get());

    // Attaching collider
    if (gameObject.get()->collider.active) {
       if(gameObject->collider.type == ColliderType::BOX_COLLIDER){
           double density = gameObject->rigidBody.mass / ((width / PPM) * (width / PPM));
           AttachBoxCollider(box2dRigidBody, gameObject->collider.GetData().at(0), gameObject->collider.GetData().at(1), density);
       }else if(gameObject->collider.type == ColliderType::CIRCLE_COLLIDER){
           double radius  = gameObject->collider.GetData().at(0);
           double density = gameObject->rigidBody.mass / (M_PI * (radius / PPM * radius / PPM));
           AttachCircleCollider(box2dRigidBody, radius, density);
       }
    }
}

void PhysicsImpl::DestroyWorld() {

}

void PhysicsImpl::DestroyBody(b2Body *body) {

}

void PhysicsImpl::AttachBoxCollider(b2Body *rigidBody, double width, double height, double density) {
    b2PolygonShape collisionShape;
    collisionShape.SetAsBox(width / 2 / PPM, height / 2 / PPM);
    if (rigidBody->GetType() != b2_staticBody) {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = density;
        fixtureDef.friction = 0.3f;
        rigidBody->CreateFixture(&fixtureDef);
    } else {
        rigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::AttachCircleCollider(b2Body *rigidBody, double radius, double density) {
    b2CircleShape collisionShape;
    collisionShape.m_radius = radius / PPM;

    if(rigidBody->GetType() != b2_staticBody){
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &collisionShape;
        fixtureDef.density = density;
        fixtureDef.friction = 0.3f;
        rigidBody->CreateFixture(&fixtureDef);
    }
    else {
        rigidBody->CreateFixture(&collisionShape, 0.0f);
    }
}

void PhysicsImpl::Update(std::shared_ptr<GameObject> gameObject) {
    for (b2Body *body = _world.GetBodyList(); body; body = body->GetNext()) {
        if (body->GetUserData() == gameObject.get()) {
            gameObject.get()->transform.position.x = body->GetPosition().x * PPM;
            gameObject.get()->transform.position.y = body->GetPosition().y * PPM;
        }
    }
}

void PhysicsImpl::Step() {
    _world.Step(1.0f / 60.0f, 8, 6);
}
