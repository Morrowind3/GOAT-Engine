#ifndef GOAT_ENGINE_ETAPPEONE_HPP
#define GOAT_ENGINE_ETAPPEONE_HPP

#include "../Templates/SharedEtappe.hpp"
#include "../../../Engine/SceneManager.hpp"

using namespace Engine;

class EtappeOne : public SharedEtappe {
    public: explicit EtappeOne(SceneManager& manager);
};

#endif //GOAT_ENGINE_ETAPPEONE_HPP
