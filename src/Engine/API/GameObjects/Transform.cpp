#include "Transform.hpp"

using namespace Engine;

Transform::Transform(Point position, unsigned int layerGroup, unsigned int layerInsideGroup, double rotation, double scaleWidth, double scaleHeight, FLIP flip):
 position{position}, layerGroup{layerGroup}, layerInsideGroup{layerInsideGroup}, rotation{rotation}, scaleWidth{scaleWidth}, scaleHeight{scaleHeight}, flip{flip} {}
