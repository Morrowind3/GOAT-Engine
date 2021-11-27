#include "PhysicsImpl.hpp"
#include <cmath>

using namespace Engine;

const float PPM = 21.0f;

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
    if (gameObject.collider.active) {
       if(gameObject.collider.type == ColliderType::BOX_COLLIDER){
           double density = gameObject.rigidBody.mass / ((width / PPM) * (width / PPM));
           AttachBoxCollider(box2dRigidBody, gameObject.collider.GetData().at(0), gameObject.collider.GetData().at(1), density);
       } else if (gameObject.collider.type == ColliderType::CIRCLE_COLLIDER){
           double radius  = gameObject.collider.GetData().at(0);
           double density = gameObject.rigidBody.mass / (M_PI * (radius / PPM * radius / PPM));
           AttachCircleCollider(box2dRigidBody, radius, density);
       }
    }
}

void PhysicsImpl::ResetForNextScene() {
    _world = std::make_unique<b2World>(b2Vec2{0.0f, 10.0f});
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

void PhysicsImpl::PerformPhysicsCalculationsForFrame() {
    _world->Step(1.0f / 60.0f, 8, 6);
}

void PhysicsImpl::UpdateGameObjectStateFromPhysicsTick(GameObject& gameObject) {
    for (b2Body *body = _world->GetBodyList(); body; body = body->GetNext()) {
        if (body->GetUserData() == &gameObject) {
            gameObject.transform.position.x = body->GetPosition().x * PPM;
            gameObject.transform.position.y = body->GetPosition().y * PPM;
        }
    }
}
