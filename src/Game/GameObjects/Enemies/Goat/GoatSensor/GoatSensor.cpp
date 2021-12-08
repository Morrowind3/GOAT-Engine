#include "GoatSensor.hpp"
#include "GoatSensorBehavior.hpp"

GoatSensor::GoatSensor(GameObject& goat, Transform transform, bool active) : GameObject(transform, active) {
//    behaviors.insert(std::make_pair("Keys::GOAT", (std::shared_ptr<GoatSensorBehavior>) std::make_shared<GoatSensorBehavior>(goat.behaviors.at(""), *this, true)));
}