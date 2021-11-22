//
// Created by MDstu on 22/11/2021.
//

#include "BoxCollider.hpp"

using namespace Engine;

BoxCollider::BoxCollider(double width, double height, bool active) : Collider(active), width(width), height(height) {}