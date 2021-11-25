#ifndef GOAT_ENGINE_KEYS_HPP
#define GOAT_ENGINE_KEYS_HPP
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <string>

/// Keys to identify scenes/objects/components and the like
namespace Keys {
    const std::string BEHAVIOR = "BEHAVIOR"; // Usage: generic behavior ID for single script behaviors
    // (Hawk, Player, Quit, SwitchScene SlabTile, Tile, FPS)
	const std::string SPRITE = "SPRITE"; // Usage: generic sprite ID for single sprite objects
	// (Tile)
    const std::string TRUE = "TRUE"; // Usage: positive bool (pause)
    const std::string FALSE = "FALSE"; // Usage: negative bool (pause)
	const std::string BACKGROUND = "BACKGROUND"; // Usage: generic background ID (EtappeOne)
	const std::string ETAPPE = "ETAPPE"; // Usage: Etappe behavior ID on all etappe managers
	const std::string ETAPPE_SELECT = "ETAPPE_SELECT"; // Usage: Etappe selection scene ID
    const std::string SNOWSTORM = "SNOWSTORM"; // Usage: snowstorm ambient music
    const std::string MAIN_MENU = "MAIN_MENU"; // Usage: Main menu level ID
    const std::string SCOREBOARD_MENU = "SCOREBOARD_MENU"; // Usage: Scoreboard menu level ID
    const std::string SETTINGS_MENU =  "SETTINGS_MENU"; // Usage: Settings menu level ID
    const std::string ETAPPE_ONE = "ETAPPE_ONE"; // Usage: Etappe 1 level ID
    const std::string ETAPPE_TWO = "ETAPPE_TWO"; // Usage: Etappe 2 level ID
    const std::string START_GAME = "START_GAME"; // Usage: Start game button ID
    const std::string QUIT_GAME = "QUIT_GAME"; // Usage: Quit game button ID
    const std::string FPS = "FPS"; // Usage: FPS text ID, FPS object ID, FPS script ID
    const std::string PAUSE = "PAUSE"; // Usage: global scene key to check if game is paused, pause script ID
	const std::string PAUSE_SFX = "PAUSE_SFX"; // Usage: pause SFX ID
    const std::string HAWK = "HAWK"; // Usage: Hawk script ID
    const std::string MOVE1 = "MOVE1"; // Usage: Hawk sprite 1, Player walk sprite 1
    const std::string MOVE2 = "MOVE2"; // Usage: Hawk sprite 2
	const std::string IDLE = "IDLE"; // Usage: Player/Goat idle sprite
	const std::string IDLE2 = "IDLE2"; // Usage: Goat idle sprite 2
    const std::string JUMP = "JUMP"; // Usage: Player jump sprite
    const std::string JUMP_SFX = "JUMP_SFX"; // Usage: Player jump sfx
    const std::string WALK_SFX_A = "WALK_SFX_A"; // Usage: Player walk sfx, primary step
    const std::string WALK_SFX_B = "WALK_SFX_B"; // Usage: Player walk sfx, alternating step
    const std::string ATTACK_STANCE = "ATTACK_STANCE"; // Usage: Goat attack ready sprite
    const std::string ATTACK1 = "ATTACK1"; // Usage: Goat attack sprite
    const std::string ATTACK2 = "ATTACK2"; // Usage: Goat attack sprite 2
    const std::string BLEATHING = "BLEATHING"; // Usage: Goat bleathing SFX
}

#endif //GOAT_ENGINE_KEYS_HPP
