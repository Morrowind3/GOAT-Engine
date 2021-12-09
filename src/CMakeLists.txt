cmake_minimum_required(VERSION 3.16)
project(GOAT_Engine)

set(CMAKE_CXX_STANDARD 17)

SET(MINGW_STATIC_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MINGW_STATIC_FLAGS}")

set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2-2.0.16/include")
set(SDL2_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2-2.0.16/lib/x86")
set(SDL2_TTF_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_TTF-2.0.15/include")
set(SDL2_TTF_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_TTF-2.0.15/lib/x86")
set(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_IMAGE-2.0.5/include")
set(SDL2_IMAGE_LIB_DIR ${PROJECT_SOURCE_DIR}/Libraries/SDL2_IMAGE-2.0.5/lib/x86)
set(SDL2_MIXER_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_MIXER-2.0.4/include")
set(SDL2_MIXER_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_MIXER-2.0.4/lib/x86")
set(BOX2D_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/BOX2D")
#set(BOX2D_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/BOX2D/lib")
set(SQLITE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SQLite/include")
set(SQLITE_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SQLite/lib")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR} ${SQLITE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_TTF_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_MIXER_LIB_DIR} ${SQLITE_LIB_DIR})

file(GLOB_RECURSE Box2D_SRC
        Libraries/Box2D/*.h
        Libraries/Box2D/*.cpp)

add_library(TessilOrdered STATIC "Libraries/Tessil/ordered_hash.hpp" "Libraries/Tessil/ordered_set.hpp" "Libraries/Tessil/ordered_map.hpp")
set_target_properties(TessilOrdered PROPERTIES LINKER_LANGUAGE CXX)

add_library(GOAT_Engine STATIC
        ${Box2D_SRC}
        "Engine/API/GameObjects/GameComponents/GameComponent.hpp"
        "Engine/API/GameObjects/GameComponents/GameComponent.cpp"
        "Engine/API/GameObjects/GameComponents/Render/Sprite.hpp"
        "Engine/API/GameObjects/GameComponents/Render/Sprite.cpp"
        "Engine/API/GameObjects/Transform.hpp"
        "Engine/API/GameObjects/Transform.cpp"
        "Engine/API/GameObjects/Point.hpp"
        "Engine/API/GameObjects/Point.cpp"
        "Engine/API/GameObjects/GameObject.hpp"
        "Engine/API/GameObjects/GameObject.cpp"
        "Engine/API/Scene.hpp"
        "Engine/API/Scene.cpp"
        "Engine/SceneManager.hpp"
        "Engine/SceneManager.cpp"
        "Engine/Systems/RenderingSystem.hpp"
        "Engine/Systems/RenderingSystem.cpp"
        "Engine/Systems/System.hpp"
        "Engine/Systems/System.cpp"
        "Engine/Engine.hpp"
        "Engine/Engine.cpp"
        Engine/API/GameObjects/GameComponents/Collision/RigidBody.hpp
        Engine/API/GameObjects/GameComponents/Collision/RigidBody.cpp
        Engine/API/GameObjects/GameComponents/Collision/Collider.hpp
        Engine/API/GameObjects/GameComponents/Collision/Collider.cpp
		Engine/API/GameObjects/GameComponents/Collision/BoxCollider.hpp
		Engine/API/GameObjects/GameComponents/Collision/BoxCollider.cpp
		Engine/API/GameObjects/GameComponents/Collision/OvalCollider.hpp
		Engine/API/GameObjects/GameComponents/Collision/OvalCollider.cpp
        Engine/API/GameObjects/GameComponents/Collision/CircleCollider.hpp
        Engine/API/GameObjects/GameComponents/Collision/CircleCollider.cpp
        Engine/Systems/Apis/Implementations/RendererImpl.cpp
        Engine/Systems/Apis/Implementations/RendererImpl.hpp
        Engine/Systems/Apis/Implementations/Managers/Textures/Texture.cpp
        Engine/Systems/Apis/Implementations/Managers/Textures/Texture.hpp
        Engine/Systems/Apis/RendererApi.cpp
        Engine/Systems/Apis/RendererApi.hpp
        Engine/Systems/Apis/Implementations/Managers/Textures/TextureManager.cpp
        Engine/Systems/Apis/Implementations/Managers/Textures/TextureManager.hpp
        Engine/Systems/ScriptSystem.cpp
        Engine/Systems/ScriptSystem.hpp
        Engine/Systems/CollisionSystem.cpp
        Engine/Systems/CollisionSystem.hpp
        Engine/API/GameObjects/GameComponents/Script/Script.hpp
        Engine/Systems/Apis/Implementations/AudioImpl.cpp
        Engine/Systems/Apis/Implementations/AudioImpl.hpp
        Engine/Systems/Apis/AudioApi.cpp
        Engine/Systems/Apis/AudioApi.hpp
        Engine/Systems/AudioSystem.cpp
        Engine/Systems/AudioSystem.hpp
        Engine/API/GameObjects/GameComponents/Script/Script.cpp
        Engine/API/GameObjects/GameComponents/Script/Behavior.cpp
        Engine/API/GameObjects/GameComponents/Script/Behavior.hpp
        Engine/Systems/Apis/RendererApi.cpp
        Engine/Systems/Apis/RendererApi.hpp
        Engine/Utilities/Input.cpp
        Engine/Systems/Apis/Implementations/Managers/Fonts/FontManager.cpp
        Engine/Systems/Apis/Implementations/Managers/Fonts/FontManager.hpp
        Engine/Systems/Apis/RendererApi.cpp
        Engine/Systems/Apis/RendererApi.hpp
        Engine/Systems/Apis/PhysicsApi.cpp
        Engine/Systems/Apis/PhysicsApi.hpp
        Engine/Utilities/Input.cpp
        Engine/Systems/Apis/Implementations/PhysicsImpl.cpp
        Engine/Systems/Apis/Implementations/PhysicsImpl.hpp
        Engine/Systems/Apis/Implementations/Managers/Audio/AudioManager.cpp
        Engine/Systems/Apis/Implementations/Managers/Audio/AudioManager.hpp
        Engine/Systems/Apis/Implementations/Managers/Audio/Music.cpp
        Engine/Systems/Apis/Implementations/Managers/Audio/Music.hpp
        Engine/Systems/Apis/Implementations/Managers/Audio/Sample.cpp
        Engine/Systems/Apis/Implementations/Managers/Audio/Sample.hpp
        Engine/API/GameObjects/GameComponents/Audio/AudioSource.cpp
        Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp
        Engine/NoCopyNoMove.hpp
        Engine/API/GameObjects/GameComponents/Render/UI/Text.cpp
        Engine/API/GameObjects/GameComponents/Render/UI/Text.hpp
        Engine/API/GameObjects/Color.cpp
        Engine/API/GameObjects/Color.hpp
        Engine/Systems/Apis/Implementations/Managers/Fonts/Font.cpp
        Engine/Systems/Apis/Implementations/Managers/Fonts/Font.hpp
        Engine/API/GameObjects/GameComponents/Render/UI/Button.cpp
        Engine/API/GameObjects/GameComponents/Render/UI/Button.hpp
        Engine/API/GameObjects/Rectangle.cpp
        Engine/API/GameObjects/Rectangle.hpp
        Engine/Systems/Apis/DataApi.cpp
        Engine/Systems/Apis/Implementations/DataImpl.cpp
        Engine/Systems/Apis/Implementations/SqlLite/MigrationBuilder.cpp
        Engine/Systems/Apis/Implementations/SqlLite/SqlColumn.cpp
        Engine/Systems/Apis/Implementations/SqlLite/SqlTable.cpp
        Engine/Systems/Apis/Implementations/SqlLite/ForeignKey.cpp
        Engine/Systems/Apis/Implementations/SqlLite/DataModel.cpp Engine/Systems/Apis/Implementations/SqlLite/DataModel.hpp
        Engine/API/GameObjects/Rectangle.hpp 
		Engine/Utilities/Debug.cpp Engine/Utilities/Debug.hpp
		Engine/API/Camera.cpp Engine/API/Camera.hpp 
		Engine/Utilities/Globals.cpp Engine/Utilities/Globals.hpp
        Engine/Utilities/Input/InputRegistry.cpp Engine/Utilities/Input/InputRegistry.hpp
		Engine/Utilities/Input/KeyCode.hpp
		Engine/Utilities/Input/MouseButton.hpp
		Engine/Utilities/Input/PressState.hpp
        Engine/Systems/Apis/Implementations/SqlLite/DataModel.cpp
        Engine/Systems/Apis/Implementations/SqlLite/DataModel.hpp
        Engine/Systems/Apis/Implementations/Managers/Physics/ContactListener.cpp Engine/Systems/Apis/Implementations/Managers/Physics/ContactListener.hpp
		Engine/Systems/Apis/Implementations/Managers/Physics/CollisionState.hpp
		Engine/Utilities/Clock.cpp Engine/Utilities/Clock.hpp
		Engine/Utilities/EngineCalls.cpp Engine/Utilities/EngineCalls.hpp
        Engine/API/GameObjects/GameComponents/Render/Animator.cpp Engine/API/GameObjects/GameComponents/Render/Animator.hpp
		Engine/Systems/SystemHelpers/AnimatorHelper.cpp Engine/Systems/SystemHelpers/AnimatorHelper.hpp 
		Engine/API/LayerGroup.cpp Engine/API/LayerGroup.hpp
		)

target_include_directories(GOAT_Engine PUBLIC "Box2D")
target_link_libraries(GOAT_Engine TessilOrdered SDL2 SDL2_ttf SDL2_image SDL2_mixer sqlite3)

add_executable(Mount_Everestimate
        # Core
        Game/Keys.hpp
        Game/Game.cpp
        Game/GameSceneManager.cpp Game/GameSceneManager.hpp
		Game/MountEverestimateLevelConstructor.cpp Game/MountEverestimateLevelConstructor.hpp
		Game/Layers.hpp
		# Scene templates
		Game/Scenes/Templates/SharedEtappe.cpp Game/Scenes/Templates/SharedEtappe.hpp
        # Scenes
		Game/Scenes/Templates/SceneTemplate_Menu.cpp Game/Scenes/Templates/SceneTemplate_Menu.hpp
        Game/Scenes/Etappes/EtappeOne.hpp Game/Scenes/Etappes/EtappeOne.cpp
        Game/Scenes/Etappes/EtappeTwo.hpp Game/Scenes/Etappes/EtappeTwo.cpp
		Game/Scenes/Menus/MainMenuScene.hpp Game/Scenes/Menus/MainMenuScene.cpp
		Game/Scenes/Menus/EtappeSelection.cpp Game/Scenes/Menus/EtappeSelection.hpp
		Game/Scenes/Menus/SettingsMenuScene.cpp Game/Scenes/Menus/SettingsMenuScene.hpp
		Game/Scenes/Menus/ScoreboardMenuScene.cpp Game/Scenes/Menus/ScoreboardMenuScene.hpp
		Game/Scenes/Menus/VictoryScene.cpp Game/Scenes/Menus/VictoryScene.hpp
        # Objects
		Game/GameObjects/Player/Object_Player.hpp Game/GameObjects/Player/Object_Player.cpp
        Game/GameObjects/Enemies/Goat/Goat.cpp Game/GameObjects/Enemies/Goat/Goat.hpp
		Game/GameObjects/Scenes/Etappes/EtappeOneScene/EtappeOneManager.cpp Game/GameObjects/Scenes/Etappes/EtappeOneScene/EtappeOneManager.hpp
		Game/GameObjects/Scenes/Etappes/EtappeTwoScene/EtappeTwoManager.cpp Game/GameObjects/Scenes/Etappes/EtappeTwoScene/EtappeTwoManager.hpp
		Game/GameObjects/Tiles/SolidTile/SolidTile.cpp Game/GameObjects/Tiles/SolidTile/SolidTile.hpp
		Game/GameObjects/Tiles/SlabTile/SlabTile.cpp Game/GameObjects/Tiles/SlabTile/SlabTile.hpp
		Game/GameObjects/Tiles/SolidTile/SolidTile.cpp Game/GameObjects/Tiles/SolidTile/SolidTile.hpp
		Game/GameObjects/Tiles/SlabTile/SlabTile.cpp Game/GameObjects/Tiles/SlabTile/SlabTile.hpp
		Game/GameObjects/Enemies/Hawk/Hawk.cpp Game/GameObjects/Enemies/Hawk/Hawk.hpp
		Game/GameObjects/Scenes/MainMenuScene/Background.cpp
		Game/GameObjects/Scenes/MainMenuScene/ExitButton/ExitButton.cpp
		Game/GameObjects/Scenes/MainMenuScene/PlayButton.cpp
		Game/GameObjects/Scenes/EtappeSelectionScene/EtappeMarker.cpp Game/GameObjects/Scenes/EtappeSelectionScene/EtappeMarker.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/EtappeSelectionBackground.cpp Game/GameObjects/Scenes/EtappeSelectionScene/EtappeSelectionBackground.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/BackToMenuButton.cpp Game/GameObjects/Scenes/EtappeSelectionScene/BackToMenuButton.hpp
		Game/GameObjects/Utils/Cheats/Cheats.cpp Game/GameObjects/Utils/Cheats/Cheats.hpp
		Game/GameObjects/Scenes/MainMenuScene/ScoreboardButton.cpp Game/GameObjects/Scenes/MainMenuScene/ScoreboardButton.hpp
		Game/GameObjects/Scenes/MainMenuScene/SettingsButton.cpp Game/GameObjects/Scenes/MainMenuScene/SettingsButton.hpp
		Game/GameObjects/Scenes/MainMenuScene/DebugButton/DebugButton.cpp Game/GameObjects/Scenes/MainMenuScene/DebugButton/DebugButton.hpp
		Game/GameObjects/Utils/LifeHeart/LifeHeart.cpp Game/GameObjects/Utils/LifeHeart/LifeHeart.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlag.cpp Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlag.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlagBehavior.cpp Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlagBehavior.hpp
		Game/GameObjects/Scenes/Etappes/EtappeOneScene/EtappeOneText.cpp Game/GameObjects/Scenes/Etappes/EtappeOneScene/EtappeOneText.hpp
		Game/GameObjects/Utils/FpsMeter/FpsMeter.cpp Game/GameObjects/Utils/FpsMeter/FpsMeter.hpp
		Game/GameObjects/Scenes/Etappes/BackToEtappeSelectionButton.cpp Game/GameObjects/Scenes/Etappes/BackToEtappeSelectionButton.hpp
		Game/GameObjects/WorldObjects/HealthPickup/HealthPickup.cpp Game/GameObjects/WorldObjects/HealthPickup/HealthPickup.hpp
        Game/GameObjects/Tiles/LavaTile/LavaTile.cpp Game/GameObjects/Tiles/LavaTile/LavaTile.hpp
		# Behaviors
		Game/GameObjects/Scenes/Etappes/EtappeBehavior.cpp Game/GameObjects/Scenes/Etappes/EtappeBehavior.hpp
		Game/GameObjects/Player/PlayerBehavior.hpp Game/GameObjects/Player/PlayerBehavior.cpp
		Game/GameObjects/Scenes/MainMenuScene/ExitButton/QuitGameBehavior.hpp Game/GameObjects/Scenes/MainMenuScene/ExitButton/QuitGameBehavior.cpp
		Game/GameObjects/Scenes/EtappeSelectionScene/EtappeMarkerBehavior.cpp Game/GameObjects/Scenes/EtappeSelectionScene/EtappeMarkerBehavior.hpp
		Game/GameObjects/Scenes/SwitchSceneButtonBehavior.hpp Game/GameObjects/Scenes/SwitchSceneButtonBehavior.cpp
		Game/GameObjects/Enemies/Hawk/HawkBehavior.hpp Game/GameObjects/Enemies/Hawk/HawkBehavior.cpp
		Game/GameObjects/Utils/LifeHeart/LifeHeartBehavior.cpp Game/GameObjects/Utils/LifeHeart/LifeHeartBehavior.hpp
		Game/GameObjects/Utils/Cheats/CheatsBehavior.cpp Game/GameObjects/Utils/Cheats/CheatsBehavior.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlagBehavior.cpp Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlagBehavior.hpp
		Game/GameObjects/Enemies/Goat/GoatBehavior.cpp Game/GameObjects/Enemies/Goat/GoatBehavior.hpp
		Game/GameObjects/Scenes/MainMenuScene/DebugButton/ToggleDebugBehavior.cpp Game/GameObjects/Scenes/MainMenuScene/DebugButton/ToggleDebugBehavior.hpp
		Game/GameObjects/Utils/FpsMeter/FpsMeterBehavior.cpp Game/GameObjects/Utils/FpsMeter/FpsMeterBehavior.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/PauseActivationBehavior.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/PauseActivationBehavior.hpp
		Game/GameObjects/Scenes/VictoryScene/VictorySceneBehavior.cpp Game/GameObjects/Scenes/VictoryScene/VictorySceneBehavior.hpp
		Game/GameObjects/WorldObjects/HealthPickup/HealthPickupBehavior.cpp Game/GameObjects/WorldObjects/HealthPickup/HealthPickupBehavior.hpp
        Game/GameObjects/Tiles/LavaTile/LavaTileBehavior.cpp Game/GameObjects/Tiles/LavaTile/LavaTileBehavior.hpp
		Game/GameObjects/Tiles/Tile.hpp Game/GameObjects/Tiles/Tile.cpp
        Game/Scenes/Templates/SharedEtappe.cpp Game/Scenes/Templates/SharedEtappe.hpp
		Game/Scenes/Menus/DefeatScene.cpp

        Game/Animators/Animator_PlayerWalking.cpp Game/Animators/Animator_PlayerWalking.hpp

		Game/Sprites/Player/Sprite_PlayerIdle.cpp Game/Sprites/Player/Sprite_PlayerIdle.hpp
		Game/Sprites/Player/Sprite_PlayerMove1.cpp Game/Sprites/Player/Sprite_PlayerMove1.hpp
		Game/Sprites/Player/Sprite_PlayerMove3.cpp Game/Sprites/Player/Sprite_PlayerMove3.hpp
		Game/Sprites/Player/Sprite_PlayerJump.cpp Game/Sprites/Player/Sprite_PlayerJump.hpp
		Game/Sprites/Player/Sprite_PlayerMove2.cpp Game/Sprites/Player/Sprite_PlayerMove2.hpp

		Game/AudioSources/Sounds/Sound_Jump.cpp Game/AudioSources/Sounds/Sound_Jump.hpp
		Game/AudioSources/Sounds/Sound_Walk.cpp Game/AudioSources/Sounds/Sound_Walk.hpp
		Game/AudioSources/Sounds/Sound_WalkAlt.cpp Game/AudioSources/Sounds/Sound_WalkAlt.hpp 
		Game/AudioSources/Sounds/Sound_Oof.cpp Game/AudioSources/Sounds/Sound_Oof.hpp 
		Game/AudioSources/Sounds/Sound_Death.cpp Game/AudioSources/Sounds/Sound_Death.hpp
		Game/GameObjects/Scenes/SwitchSceneButtonScript.cpp Game/GameObjects/Scenes/SwitchSceneButtonScript.hpp
		Game/GameObjects/Scenes/MainMenuScene/ExitButton/QuitGameScript.cpp Game/GameObjects/Scenes/MainMenuScene/ExitButton/QuitGameScript.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/EtappeProgress.cpp Game/GameObjects/Scenes/EtappeSelectionScene/EtappeProgress.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/EtappeMarkerConfigurator.cpp Game/GameObjects/Scenes/EtappeSelectionScene/EtappeMarkerConfigurator.hpp
		Game/GameObjects/Player/PlayerMovementScript.cpp Game/GameObjects/Player/PlayerMovementScript.hpp
		Game/GameObjects/Enemies/Hawk/HawkScript.cpp Game/GameObjects/Enemies/Hawk/HawkScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/FpsScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/FpsScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/PauseScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/PauseScript.hpp
		Game/GameObjects/Utils/LifeHeart/LifeHeartScript.cpp Game/GameObjects/Utils/LifeHeart/LifeHeartScript.hpp
		Game/GameObjects/Scenes/Etappes/LifeInitScript.cpp Game/GameObjects/Scenes/Etappes/LifeInitScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsScript.cpp Game/GameObjects/Utils/Cheats/CheatsScript.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/FlagScript.cpp
		Game/GameObjects/Player/DamageScript.cpp
		Game/GameObjects/Utils/Cheats/CheatsBehavior.cpp
		Game/GameObjects/Utils/Cheats/CheatsScript.cpp
		Game/GameObjects/WorldObjects/VictoryFlag/VictoryFlag.cpp
		Game/GameObjects/Scenes/GameStateBehavior.cpp Game/GameObjects/Scenes/EtappeEndScene/GameStateScript.cpp
		Game/GameObjects/Scenes/GameStateManager.cpp
		Game/GameObjects/Scenes/EtappeEndScene/VictoryScreenManager.cpp
		Game/GameObjects/Scenes/EtappeEndScene/DefeatBackground.cpp Game/GameObjects/Scenes/EtappeEndScene/SelectEtappeButton.cpp
		Game/GameObjects/Scenes/EtappeEndScene/NextEtappeButton.cpp Game/GameObjects/Scenes/EtappeEndScene/RetryButton.cpp
		Game/GameObjects/Utils/Cheats/CheatsScript.cpp Game/GameObjects/Utils/Cheats/CheatsScript.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/FlagScript.cpp Game/GameObjects/WorldObjects/VictoryFlag/FlagScript.hpp
		Game/GameObjects/Player/DamageScript.cpp Game/GameObjects/Player/DamageScript.hpp
		Game/GameObjects/Enemies/Goat/GoatScript.cpp Game/GameObjects/Enemies/Goat/GoatScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/SummonScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/SummonScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/DamageCheatScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/DamageCheatScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/SpeedScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/SpeedScript.hpp
		Game/GameObjects/WorldObjects/HealthPickup/HealScript.cpp Game/GameObjects/WorldObjects/HealthPickup/HealScript.hpp
        Game/GameObjects/Tiles/LavaTile/LavaTileScript.cpp Game/GameObjects/Tiles/LavaTile/LavaTileScript.hpp
		Game/GameObjects/Scenes/MainMenuScene/DebugButton/DebugToggleScript.cpp Game/GameObjects/Scenes/MainMenuScene/DebugButton/DebugToggleScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/PauseActivationScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/PauseActivationScript.hpp
		Game/GameObjects/Scenes/VictoryScene/IncreaseEtappeCountScript.cpp Game/GameObjects/Scenes/VictoryScene/IncreaseEtappeCountScript.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/BeatLevelScript.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/BeatLevelScript.hpp
		Game/GameObjects/Enemies/Snake/Snake.cpp Game/GameObjects/Enemies/Snake/Snake.hpp Game/GameObjects/Enemies/Snake/SnakeBehavior.cpp Game/GameObjects/Enemies/Snake/SnakeBehavior.hpp Game/GameObjects/Enemies/Snake/SnakeScript.cpp Game/GameObjects/Enemies/Snake/SnakeScript.hpp
		Game/GameObjects/Scenes/Etappes/EtappeTwoScene/EtappeTwoText.cpp Game/GameObjects/Scenes/Etappes/EtappeTwoScene/EtappeTwoText.hpp
		Game/GameObjects/Utils/Timer/Timer.cpp Game/GameObjects/Utils/Timer/Timer.hpp
		Game/GameObjects/Utils/Timer/TimerBehavior.cpp Game/GameObjects/Utils/Timer/TimerBehavior.hpp
		Game/GameObjects/Utils/Timer/TimerLine.cpp Game/GameObjects/Utils/Timer/TimerLine.hpp
		Game/GameObjects/Utils/Timer/TimerLineBehavior.cpp Game/GameObjects/Utils/Timer/TimerLineBehavior.hpp
		Game/GameObjects/Utils/Timer/TimerLineScript.cpp Game/GameObjects/Utils/Timer/TimerLineScript.hpp
		Game/GameObjects/Utils/Timer/TimerScript.cpp Game/GameObjects/Utils/Timer/TimerScript.cpp Game/GameObjects/WorldObjects/Trash/Trash.cpp Game/GameObjects/WorldObjects/Trash/Trash.hpp Game/GameObjects/WorldObjects/Trash/TrashBehavior.cpp Game/GameObjects/WorldObjects/Trash/TrashBehavior.hpp Game/GameObjects/WorldObjects/Trash/TrashScript.cpp Game/GameObjects/WorldObjects/Trash/TrashScript.hpp Game/GameObjects/Utils/TrashCounter/TrashCounter.cpp Game/GameObjects/Utils/TrashCounter/TrashCounter.hpp Game/GameObjects/Utils/TrashCounter/TrashCounterBehavior.cpp Game/GameObjects/Utils/TrashCounter/TrashCounterBehavior.hpp Game/GameObjects/Utils/TrashCounter/TrashCounterScript.cpp Game/GameObjects/Utils/TrashCounter/TrashCounterScript.hpp
		Game/GameObjects/Utils/Timer/TimerScript.cpp Game/GameObjects/Utils/Timer/TimerScript.cpp Game/Scenes/Etappes/EtappeThree.cpp Game/Scenes/Etappes/EtappeThree.hpp
		Game/GameObjects/Scenes/Etappes/EtappeThreeScene/EtappeThreeManager.cpp Game/GameObjects/Scenes/Etappes/EtappeThreeScene/EtappeThreeManager.hpp Game/Scenes/Etappes/EtappeFour.cpp Game/Scenes/Etappes/EtappeFour.hpp Game/GameObjects/Scenes/Etappes/EtappeFourScene/EtappeFourManager.cpp Game/GameObjects/Scenes/Etappes/EtappeFourScene/EtappeFourManager.hpp Game/GameObjects/Enemies/Snowball/Snowball.cpp Game/GameObjects/Enemies/Snowball/Snowball.hpp Game/GameObjects/Enemies/Snowball/SnowballBehavior.cpp Game/GameObjects/Enemies/Snowball/SnowballBehavior.hpp Game/GameObjects/Enemies/Snowball/SnowballScript.cpp Game/GameObjects/Enemies/Snowball/SnowballScript.hpp
		Game/GameObjects/Scenes/Etappes/EtappeThreeScene/EtappeThreeManager.cpp Game/GameObjects/Scenes/Etappes/EtappeThreeScene/EtappeThreeManager.hpp
		Game/Scenes/Etappes/EtappeFive.cpp Game/Scenes/Etappes/EtappeFive.hpp Game/GameObjects/Scenes/Etappes/EtappeFiveScene/EtappeFiveManager.cpp Game/GameObjects/Scenes/Etappes/EtappeFiveScene/EtappeFiveManager.hpp Game/GameObjects/Tiles/WallTile/WallTile.cpp Game/GameObjects/Tiles/WallTile/WallTile.hpp)

target_link_libraries(Mount_Everestimate GOAT_Engine SDL2main)

add_executable(engine_tests "Engine/Tests/_Test.cpp" Engine/Tests/AnimatorHelperTest.cpp)
target_link_libraries(engine_tests GOAT_Engine SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer)

add_executable(game_tests "Game/Tests/PlayerTest.cpp")
target_link_libraries(engine_tests GOAT_Engine)
enable_testing()
# Place all necessary dlls and assets in build folder
add_custom_command(TARGET Mount_Everestimate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/DLLs
        ${PROJECT_SOURCE_DIR}/Game/Resources
        $<TARGET_FILE_DIR:Mount_Everestimate>)