#ifndef GOAT_ENGINE_KEYS_HPP
#define GOAT_ENGINE_KEYS_HPP
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <string>

/// Keys to identify scenes/objects/components and the like, please (re-)sort to the appropriate region
/// (yes this got messy quickly, but this ensures all possible keys are in one place)
namespace Keys {

#pragma region Logic
    const std::string TRUE = "TRUE"; // Usage: positive bool
    const std::string FALSE = "FALSE"; // Usage: negative bool
    const std::string ERROR = "ERROR"; // Usage: error identifier
    const std::string NO_FLIP = "ERROR"; // Usage: Indicate that this sprite shouldn't be flipped. e.g. You want text to remain legible.
#pragma endregion

#pragma region Generic Identifiers
	const std::string _; // Preferable "empty" key
	const std::string SCRIPT = "SCRIPT";
    const std::string BEHAVIOR = "BEHAVIOR";
    const std::string SPRITE = "SPRITE";
	const std::string ANIMATOR = "ANIMATOR";
	const std::string TEXT = "TEXT";
	const std::string AUDIO = "AUDIO";
    const std::string MUSIC = "MUSIC";
	const std::string BACKGROUND = "BACKGROUND";
#pragma endregion

#pragma region Scene IDs
    // Etappes
    const std::string ETAPPE_ONE = "ETAPPE_1"; // Usage: Etappe 1 level ID
    const std::string ETAPPE_TWO = "ETAPPE_2"; // Usage: Etappe 2 level ID
	const std::string ETAPPE_THREE = "ETAPPE_3"; // Usage: Etappe 3 level ID
	const std::string ETAPPE_FOUR = "ETAPPE_4"; // Usage: Etappe 4 level ID
	const std::string ETAPPE_FIVE = "ETAPPE_5"; // Usage: Etappe 5 level ID
    // Menus
    const std::string VICTORY_SCREEN = "VICTORY_SCREEN"; //Usage: Victory screen level ID
    const std::string DEFEAT_SCREEN = "DEFEAT_SCREEN"; //Usage: Defeat screen level ID
    const std::string ETAPPE_SELECT = "ETAPPE_SELECT"; // Usage: Etappe selection level ID
    const std::string MAIN_MENU = "MAIN_MENU"; // Usage: Main menu level ID
    const std::string SCOREBOARD_MENU = "SCOREBOARD_MENU"; // Usage: Scoreboard menu level ID
    const std::string SETTINGS_MENU = "SETTINGS_MENU"; // Usage: Settings menu level ID
    const std::string SAVE_MENU = "SAVE_MENU"; // Usage: Save menu level ID
    const std::string CREDITS_MENU = "CREDITS_MENU"; // Usage: Credits menu level ID
#pragma endregion

#pragma region Player Data
	const std::string CURRENT_PLAYER_ID = "CURRENT_PLAYER_ID"; // Usage: ID of the player currently playing
	const std::string ETAPPES_UNLOCKED = "ETAPPES_UNLOCKED"; // Usage: Amount of etappes unlocked
	const std::string DIFFICULTY = "DIFFICULTY"; // Usage: Difficulty, which adjusts how quick the line goes
	const std::string VOLUME = "VOLUME"; // Usage: Volume level
#pragma endregion

#pragma region Etappe Events
    const std::string ETAPPE = "ETAPPE"; // Usage: Etappe behavior ID on all etappe managers
    const std::string ETAPPE_PROGRESS = "ETAPPE_PROGRESS"; // Usage: Etappe progress script ID
    const std::string ETAPPE_CONFIG = "ETAPPE_CONFIG"; // Usage: Etappe config script ID
    const std::string NEXT_ETAPPE = "NEXT_ETAPPE"; // Usage: Flag to request the next stage
    const std::string CURRENT_ETAPPE = "CURRENT_ETAPPE"; // Usage: Flag to request the current stage
#pragma endregion

#pragma region Player
    const std::string WALKING_ANIMATOR = "WALKING_ANIMATOR";
#pragma endregion

#pragma region Save Menu
	const std::string SAVE_FILE = "SAVE_FILE";
	const std::string SAVE_ID = "SAVE_ID";
	const std::string SAVE_AVATAR = "SAVE_AVATAR";
	const std::string SAVE_UNLOCKED = "SAVE_UNLOCKED";
	const std::string SAVE_SCORE = "SAVE_SCORE";
	const std::string SAVE_PLAY = "SAVE_PLAY";
	const std::string SAVE_ERASE = "SAVE_ERASE";
#pragma endregion

#pragma region Scoreboard
    const std::string ALL_ETAPPES = "ALL_ETAPPES";
    const std::string SCOREBOARD_ENTRY = "SCOREBOARD_ENTRY";
	const std::string SCOREBOARD_INITIAL_LOAD = "SCOREBOARD_INITIAL_LOAD";
#pragma endregion

#pragma region Scoreboard Rain
    const std::string RAIN = "RAIN";
    const std::string RAIN2 = "RAIN2";
	const std::string RAIN3 = "RAIN3";
	const std::string RAIN4 = "RAIN4";
#pragma endregion

#pragma region Trash
    const std::string TRASH = "TRASH"; // Usage: Object_Trash Object ID and for counting collected trash
    const std::string TRASH_MAX = "TRASH_MAX"; // Usage: Object_Trash Object ID and for the total trash in a scene.
    const std::string TRASH_0 = "TRASH_0";
    const std::string TRASH_1 = "TRASH_1";
    const std::string TRASH_2 = "TRASH_2";
    const std::string TRASH_3 = "TRASH_3";
#pragma endregion

#pragma region Game State
	const std::string FLAG_LOCATION = "FLAG_LOCATION";
	const std::string LINE_LOCATION = "LINE_LOCATION";
    const std::string GAMESTATE = "GAMESTATE";
    const std::string GAMESTATE_DEFAULT = "DEFAULT";
    const std::string GAMESTATE_VICTORY = "VICTORY";
    const std::string GAMESTATE_DEFEAT = "DEFEAT";
#pragma endregion

#pragma region Game Speed
    const std::string SPEED_UP = "SPEED_UP";
    const std::string SLOW_DOWN = "SLOW_DOWN";
    const std::string RESET_SPEED = "RESET_SPEED";
#pragma endregion

#pragma region Unsorted
	const std::string TIMER_TEXT = "TIMER_TEXT";
    const std::string SNOWSTORM = "SNOWSTORM";
    const std::string FPS = "FPS"; // Usage: FPS text ID, FPS object ID, FPS script ID
    const std::string PAUSE = "PAUSE"; // Usage: global scene key to check if game is paused, pause script ID
	const std::string SPEED = "SPEED";
    const std::string HAWK = "HAWK"; // Usage: Object_Hawk script ID
    const std::string GOAT = "GOAT"; // Usage: Object_Goat script ID
    const std::string SNAKE = "SNAKE"; // Usage: Object_Snake script ID
    const std::string SNOWBALL = "SNOWBALL"; // Usage: Object_Snowball script ID
    const std::string PLAYER = "PLAYER"; // Usage: Player Object ID

    const std::string MOVE1 = "MOVE1"; // Usage: Object_Hawk sprite 1, Player walk sprite 1
    const std::string MOVE2 = "MOVE2"; // Usage: Object_Hawk sprite 2
    const std::string MOVE3 = "MOVE3";
	const std::string IDLE = "IDLE"; // Usage: Object_Player/Object_Goat idle sprite
	const std::string IDLE2 = "IDLE2"; // Usage: Object_Goat idle sprite 2
    const std::string JUMP = "JUMP"; // Usage: Object_Player jump sprite
    const std::string ATTACK_STANCE = "ATTACK_STANCE"; // Usage: Object_Goat attack ready sprite
    const std::string ATTACK1 = "ATTACK1"; // Usage: Object_Goat attack sprite
    const std::string ATTACK2 = "ATTACK2"; // Usage: Object_Goat attack sprite 2
	const std::string CLOUDS = "CLOUDS"; // Usage: Object_Cloud sprite (EtappeSelectionBG)
	const std::string HP = "HP"; // Usage: Health scene-global-var key, HP script (etappe behavior)
    const std::string JAGERPLEISTER = "JAGERPLEISTER"; // Usage: For Jägerpleister sprite.
    const std::string DAMAGE = "DAMAGE"; // Usage: Use for the damage script, which you attach to objects that can receive damage.
    const std::string TIMER = "TIMER"; // Usage: Used by the Timer.
    const std::string CHEATS = "CHEATS";
    const std::string LEVEL_DEBUG = "LEVEL_DEBUG"; // Usage: game global flag to debug level construction
	const std::string INPUT_DEBUG = "INPUT_DEBUG"; // Usage: game global flag to debug input
    const std::string AEROPLANE = "AEROPLANE"; // Usage: For the Airplane object;
    const std::string BANNER = "BANNER"; // Usage: For the banner that can be attached to the Airplane object.
    const std::string ADVERTISEMENT = "ADVERTISEMENT"; //Usage: For the web-based advertisement object

    //BUTTONS
    const std::string START_GAME = "START_GAME"; // Usage: Start game button ID
    const std::string QUIT_GAME = "QUIT_GAME"; // Usage: Quit game button ID
    const std::string RETRY_BUTTON = "RETRY"; // Usage: Start game button ID
    const std::string CONTINUE_BUTTON = "CONTINUE"; // Usage: Start game button ID
	
    //SOUND EFFECTS
    const std::string PAUSE_SFX = "PAUSE_SFX"; // Usage: pause SFX ID
    const std::string WALK_SFX_A = "WALK_SFX_A"; // Usage: Object_Player walk sfx, primary step
    const std::string WALK_SFX_B = "WALK_SFX_B"; // Usage: Object_Player walk sfx, alternating step
    const std::string DAMAGE_SFX = "DAMAGE_SFX"; // For damage sound effects
    const std::string DEATH_SFX = "DEATH_SFX"; // For death sound effects
    const std::string JUMP_SFX = "JUMP_SFX"; // Usage: Object_Player jump sfx
    const std::string BLEATHING = "BLEATHING"; // Usage: Object_Goat bleathing SFX

    //GAME STATES, flags used by Script_GameState.



    //TAGS
	//TILES
	const std::string TILE = "TILE";
	const std::string SOLID = "SOLID";
    const std::string SLAB = "SLAB";
    const std::string WALL = "WALL";
#pragma endregion

}

#endif //GOAT_ENGINE_KEYS_HPP
