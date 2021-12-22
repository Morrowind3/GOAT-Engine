#ifndef GOAT_ENGINE_GLOBALS_HPP
#define GOAT_ENGINE_GLOBALS_HPP

#include <map>
#include <memory>
#include <string>

namespace Engine {
    class ScriptSystem; // Friend class link
    class Globals {
        public:
            friend class Engine::ScriptSystem;
            Globals(Globals const&) = delete;
            void operator=(Globals const&) = delete;
            static Globals& getInstance() {
                static Globals instance;
                return instance;
            }
            // Scene-scope
            void sceneStore(const std::string& key, const std::string& value);
            [[nodiscard]] bool sceneExists(const std::string& key) const;
            [[nodiscard]] std::string sceneGet(const std::string& key) const;
            void sceneRemove(const std::string& key);
            // Game-scope
            void gameStore(const std::string& key, const std::string& value);
            [[nodiscard]] bool gameExists(const std::string& key) const;
            [[nodiscard]] std::string gameGet(const std::string& key) const;
            void gameRemove(const std::string& key);
#ifndef TEST_ENVIRONMENT
        private:
#endif
            Globals()= default;
            void sceneReset(); // Should only be called by Engine::ScriptSystem on scene switch
            // Put on heap so that a lot of globals can be supported
            std::unique_ptr<std::map<std::string,std::string>> _sceneGlobals = std::make_unique<std::map<std::string,std::string>>();
            std::unique_ptr<std::map<std::string,std::string>> _gameGlobals = std::make_unique<std::map<std::string,std::string>>();
    };
}

#endif //GOAT_ENGINE_GLOBALS_HPP
