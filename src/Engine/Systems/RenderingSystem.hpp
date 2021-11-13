#pragma once

#include "System.hpp"

class RenderingSystem : public System {
	public:
		explicit RenderingSystem(const Scene* scene);
		void OnInit();
		void OnUpdate();
		void OnUpdateDebug();
		void OnDestroy();
	private:
};
