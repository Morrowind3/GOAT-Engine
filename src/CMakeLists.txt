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
        # Scenes
		Game/Scenes/Etappes/SharedEtappe.cpp Game/Scenes/Etappes/SharedEtappe.hpp
        Game/Scenes/Etappes/EtappeOne.hpp Game/Scenes/Etappes/EtappeOne.cpp
        Game/Scenes/Etappes/EtappeTwo.hpp Game/Scenes/Etappes/EtappeTwo.cpp
        Game/Scenes/MainMenuScene.hpp Game/Scenes/MainMenuScene.cpp
        Game/Scenes/EtappeSelection.cpp Game/Scenes/EtappeSelection.hpp
		Game/Scenes/SettingsMenuScene.cpp Game/Scenes/SettingsMenuScene.hpp
		Game/Scenes/ScoreboardMenuScene.cpp Game/Scenes/ScoreboardMenuScene.hpp
        # Objects
        Game/GameObjects/Characters/Player.hpp Game/GameObjects/Characters/Player.cpp
        Game/GameObjects/Enemies/Goat.cpp Game/GameObjects/Enemies/Goat.hpp
		Game/GameObjects/Meta/Etappes/EtappeOneManager.cpp Game/GameObjects/Meta/Etappes/EtappeOneManager.hpp
		Game/GameObjects/Meta/Etappes/EtappeTwoManager.cpp Game/GameObjects/Meta/Etappes/EtappeTwoManager.hpp
        Game/GameObjects/Tiles/Tile.hpp Game/GameObjects/Tiles/Tile.cpp
        Game/GameObjects/Tiles/SolidTile.cpp Game/GameObjects/Tiles/SolidTile.hpp
        Game/GameObjects/Tiles/SlabTile.cpp Game/GameObjects/Tiles/SlabTile.hpp
        Game/GameObjects/Tiles/SolidTile.cpp Game/GameObjects/Tiles/SolidTile.hpp
        Game/GameObjects/Tiles/SlabTile.cpp Game/GameObjects/Tiles/SlabTile.hpp
        Game/GameObjects/Enemies/Hawk.cpp Game/GameObjects/Enemies/Hawk.hpp
        Game/GameObjects/Meta/MainMenu/Background.cpp
        Game/GameObjects/Meta/MainMenu/ExitButton.cpp
        Game/GameObjects/Meta/MainMenu/PlayButton.cpp
		Game/GameObjects/Meta/EtappeSelection/EtappeMarker.cpp Game/GameObjects/Meta/EtappeSelection/EtappeMarker.hpp
		Game/GameObjects/Meta/EtappeSelection/EtappeSelectionBackground.cpp Game/GameObjects/Meta/EtappeSelection/EtappeSelectionBackground.hpp
		Game/GameObjects/Meta/EtappeSelection/BackToMenuButton.cpp Game/GameObjects/Meta/EtappeSelection/BackToMenuButton.hpp
		Game/GameObjects/Meta/Cheats.cpp Game/GameObjects/Meta/Cheats.hpp
		Game/GameObjects/Meta/MainMenu/ScoreboardButton.cpp Game/GameObjects/Meta/MainMenu/ScoreboardButton.hpp
		Game/GameObjects/Meta/MainMenu/SettingsButton.cpp Game/GameObjects/Meta/MainMenu/SettingsButton.hpp
		Game/GameObjects/Meta/MainMenu/DebugButton.cpp Game/GameObjects/Meta/MainMenu/DebugButton.hpp
		Game/GameObjects/Meta/Hud/LifeHeart.cpp Game/GameObjects/Meta/Hud/LifeHeart.hpp
		Game/GameObjects/WorldObjects/VictoryFlag.cpp Game/GameObjects/WorldObjects/VictoryFlag.hpp
		Game/Behaviors/WorldObjects/VictoryFlagBehavior.cpp Game/Behaviors/WorldObjects/VictoryFlagBehavior.hpp
		Game/GameObjects/Meta/Etappes/EtappeOneText.cpp Game/GameObjects/Meta/Etappes/EtappeOneText.hpp
		Game/GameObjects/Meta/Hud/FpsMeter.cpp Game/GameObjects/Meta/Hud/FpsMeter.hpp
		Game/GameObjects/Meta/Etappes/BackToEtappeSelectionButton.cpp Game/GameObjects/Meta/Etappes/BackToEtappeSelectionButton.hpp
		Game/GameObjects/WorldObjects/HealthPickup.cpp Game/GameObjects/WorldObjects/HealthPickup.hpp
		Game/GameObjects/Tiles/LavaTile.cpp Game/GameObjects/Tiles/LavaTile.hpp
		# Behaviors
		Game/Behaviors/Utils/EtappeBehavior.cpp Game/Behaviors/Utils/EtappeBehavior.hpp
		Game/Behaviors/Characters/PlayerBehavior.hpp Game/Behaviors/Characters/PlayerBehavior.cpp
        Game/Behaviors/Buttons/QuitGameBehavior.hpp Game/Behaviors/Buttons/QuitGameBehavior.cpp
		Game/Behaviors/Buttons/EtappeMarkerBehavior.cpp Game/Behaviors/Buttons/EtappeMarkerBehavior.hpp
		Game/Behaviors/Buttons/SwitchSceneButtonBehavior.hpp Game/Behaviors/Buttons/SwitchSceneButtonBehavior.cpp
		Game/Behaviors/Characters/HawkBehavior.hpp Game/Behaviors/Characters/HawkBehavior.cpp
        Game/Behaviors/Utils/LifeHeartBehavior.cpp Game/Behaviors/Utils/LifeHeartBehavior.hpp
		Game/Behaviors/Utils/CheatsBehavior.cpp Game/Behaviors/Utils/CheatsBehavior.hpp
		Game/Behaviors/WorldObjects/VictoryFlagBehavior.cpp Game/Behaviors/WorldObjects/VictoryFlagBehavior.hpp
		Game/Behaviors/Characters/GoatBehavior.cpp Game/Behaviors/Characters/GoatBehavior.hpp
		Game/Behaviors/Buttons/ToggleDebugBehavior.cpp Game/Behaviors/Buttons/ToggleDebugBehavior.hpp
		Game/Behaviors/Utils/FpsMeterBehavior.cpp Game/Behaviors/Utils/FpsMeterBehavior.hpp
		Game/Behaviors/Utils/PauseActivationBehavior.cpp Game/Behaviors/Utils/PauseActivationBehavior.hpp
		Game/Behaviors/Utils/VictoryScreenBehavior.cpp Game/Behaviors/Utils/VictoryScreenBehavior.hpp
		Game/Behaviors/WorldObjects/HealthPickupBehavior.cpp Game/Behaviors/WorldObjects/HealthPickupBehavior.hpp
		Game/Behaviors/Tiles/LavaTileBehavior.cpp Game/Behaviors/Tiles/LavaTileBehavior.hpp
        # Scripts
		Game/Behaviors/Buttons/Scripts/SwitchSceneButtonScript.cpp Game/Behaviors/Buttons/Scripts/SwitchSceneButtonScript.hpp
		Game/Behaviors/Buttons/Scripts/QuitGameScript.cpp Game/Behaviors/Buttons/Scripts/QuitGameScript.hpp
		Game/Behaviors/Buttons/Scripts/EtappeProgress.cpp Game/Behaviors/Buttons/Scripts/EtappeProgress.hpp
		Game/Behaviors/Buttons/Scripts/EtappeMarkerConfigurator.cpp Game/Behaviors/Buttons/Scripts/EtappeMarkerConfigurator.hpp
		Game/Behaviors/Characters/Scripts/PlayerMovementScript.cpp Game/Behaviors/Characters/Scripts/PlayerMovementScript.hpp
        Game/Behaviors/Characters/Scripts/HawkScript.cpp Game/Behaviors/Characters/Scripts/HawkScript.hpp
		Game/Behaviors/Utils/Scripts/Cheats/FpsScript.cpp Game/Behaviors/Utils/Scripts/Cheats/FpsScript.hpp
		Game/Behaviors/Utils/Scripts/Cheats/PauseScript.cpp Game/Behaviors/Utils/Scripts/Cheats/PauseScript.hpp
		Game/Behaviors/Utils/Scripts/LifeHeartScript.cpp Game/Behaviors/Utils/Scripts/LifeHeartScript.hpp
		Game/Behaviors/Utils/Scripts/LifeInitScript.cpp Game/Behaviors/Utils/Scripts/LifeInitScript.hpp
		Game/Scenes/Etappes/SharedEtappe.cpp Game/Scenes/Etappes/SharedEtappe.hpp
        Game/Behaviors/Utils/Scripts/InputPrintScript.cpp Game/Behaviors/Utils/Scripts/InputPrintScript.hpp
		Game/Behaviors/Utils/Scripts/CheatsScript.cpp Game/Behaviors/Utils/Scripts/CheatsScript.hpp
		Game/Behaviors/WorldObjects/Scripts/FlagScript.cpp
		Game/Behaviors/Utils/Scripts/DamageScript.cpp
        Game/Behaviors/Utils/Scripts/InputPrintScript.cpp
		Game/Behaviors/Utils/CheatsBehavior.cpp
		Game/Behaviors/Utils/Scripts/CheatsScript.cpp
		Game/GameObjects/WorldObjects/VictoryFlag.cpp
		Game/Behaviors/Utils/GameStateBehavior.cpp	Game/Behaviors/Utils/Scripts/GameStateScript.cpp
		Game/GameObjects/Meta/EtappeEnd/GameStateManager.cpp Game/Scenes/VictoryScene.cpp
		Game/Scenes/DefeatScene.cpp Game/GameObjects/Meta/EtappeEnd/VictoryScreenManager.cpp
		Game/GameObjects/Meta/EtappeEnd/DefeatBackground.cpp Game/GameObjects/Meta/EtappeEnd/SelectEtappeButton.cpp
		Game/GameObjects/Meta/EtappeEnd/NextEtappeButton.cpp Game/GameObjects/Meta/EtappeEnd/RetryButton.cpp
        Game/Behaviors/Utils/Scripts/InputPrintScript.cpp Game/Behaviors/Utils/Scripts/InputPrintScript.hpp
		Game/Behaviors/Utils/Scripts/CheatsScript.cpp Game/Behaviors/Utils/Scripts/CheatsScript.hpp
		Game/Behaviors/WorldObjects/Scripts/FlagScript.cpp Game/Behaviors/WorldObjects/Scripts/FlagScript.hpp
		Game/Behaviors/Utils/Scripts/DamageScript.cpp Game/Behaviors/Utils/Scripts/DamageScript.hpp
		Game/Behaviors/Characters/Scripts/GoatScript.cpp Game/Behaviors/Characters/Scripts/GoatScript.hpp
        Game/Behaviors/Utils/Scripts/Cheats/SummonScript.cpp Game/Behaviors/Utils/Scripts/Cheats/SummonScript.hpp 
        Game/Behaviors/Utils/Scripts/Cheats/DamageCheatScript.cpp Game/Behaviors/Utils/Scripts/Cheats/DamageCheatScript.hpp
		Game/Behaviors/Utils/Scripts/Cheats/SpeedScript.cpp Game/Behaviors/Utils/Scripts/Cheats/SpeedScript.hpp
		Game/Behaviors/WorldObjects/Scripts/HealScript.cpp Game/Behaviors/WorldObjects/Scripts/HealScript.hpp
        Game/Behaviors/Tiles/Scripts/LavaTileScript.cpp Game/Behaviors/Tiles/Scripts/LavaTileScript.hpp
		Game/Behaviors/Buttons/Scripts/DebugToggleScript.cpp Game/Behaviors/Buttons/Scripts/DebugToggleScript.hpp
		Game/Behaviors/Utils/Scripts/PauseActivationScript.cpp Game/Behaviors/Utils/Scripts/PauseActivationScript.hpp
        Game/Behaviors/Utils/Scripts/IncreaseEtappeCountScript.cpp Game/Behaviors/Utils/Scripts/IncreaseEtappeCountScript.hpp
		Game/Behaviors/Utils/Scripts/Cheats/BeatLevelScript.cpp Game/Behaviors/Utils/Scripts/Cheats/BeatLevelScript.hpp
        Game/GameObjects/Meta/Hud/Timer.cpp Game/GameObjects/Meta/Hud/Timer.hpp Game/Behaviors/Utils/TimerBehavior.cpp Game/Behaviors/Utils/TimerBehavior.hpp Game/Behaviors/Utils/Scripts/TimerScript.cpp Game/Behaviors/Utils/Scripts/TimerScript.hpp)
		Game/GameObjects/Enemies/Snake.cpp Game/GameObjects/Enemies/Snake.hpp Game/Behaviors/Characters/SnakeBehavior.cpp Game/Behaviors/Characters/SnakeBehavior.hpp Game/Behaviors/Characters/Scripts/SnakeScript.cpp Game/Behaviors/Characters/Scripts/SnakeScript.hpp)

target_link_libraries(Mount_Everestimate GOAT_Engine SDL2main)

add_executable(engine_tests "Engine/Tests/SampleTest.cpp")
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