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
        Engine/Systems/Apis/Implementations/Managers/Textures/TickTextureCacheData.cpp Engine/Systems/Apis/Implementations/Managers/Textures/TickTextureCacheData.hpp
		Engine/Utilities/Http.cpp Engine/Utilities/Http.hpp)


target_include_directories(GOAT_Engine PUBLIC "Box2D")
target_link_libraries(GOAT_Engine TessilOrdered SDL2 SDL2_ttf SDL2_image SDL2_mixer sqlite3)

add_executable(Mount_Everestimate
        Game/Keys.hpp
        Game/Game.cpp
        Game/GameSceneManager.cpp Game/GameSceneManager.hpp
		Game/MountEverestimateLevelConstructor.cpp Game/MountEverestimateLevelConstructor.hpp
		Game/Layers.hpp
		Game/Scenes/Templates/SceneTemplate_Etappe.cpp Game/Scenes/Templates/SceneTemplate_Etappe.hpp
		Game/Scenes/Templates/SceneTemplate_Menu.cpp Game/Scenes/Templates/SceneTemplate_Menu.hpp
		Game/Scenes/Etappes/Scene_EtappeOne.hpp Game/Scenes/Etappes/Scene_EtappeOne.cpp
		Game/Scenes/Etappes/Scene_EtappeTwo.hpp Game/Scenes/Etappes/Scene_EtappeTwo.cpp
		Game/Scenes/Menus/Scene_MainMenu.hpp Game/Scenes/Menus/Scene_MainMenu.cpp
		Game/Scenes/Menus/Scene_EtappeSelectionMenu.cpp Game/Scenes/Menus/Scene_EtappeSelectionMenu.hpp
		Game/Scenes/Menus/Scene_SettingsMenu.cpp Game/Scenes/Menus/Scene_SettingsMenu.hpp
		Game/Scenes/Menus/Scene_ScoreboardMenu.cpp Game/Scenes/Menus/Scene_ScoreboardMenu.hpp
		Game/Scenes/Menus/Scene_VictoryMenu.cpp Game/Scenes/Menus/Scene_VictoryMenu.hpp
		Game/GameObjects/Player/Object_Player.hpp Game/GameObjects/Player/Object_Player.cpp
		Game/GameObjects/Enemies/Goat/Object_Goat.cpp Game/GameObjects/Enemies/Goat/Object_Goat.hpp
		Game/GameObjects/Scenes/Etappes/EtappeOneScene/Object_EtappeOneManager.cpp Game/GameObjects/Scenes/Etappes/EtappeOneScene/Object_EtappeOneManager.hpp
		Game/GameObjects/Scenes/Etappes/EtappeTwoScene/Object_EtappeTwoManager.cpp Game/GameObjects/Scenes/Etappes/EtappeTwoScene/Object_EtappeTwoManager.hpp
		Game/GameObjects/Tiles/SolidTile/Object_SolidTile.cpp Game/GameObjects/Tiles/SolidTile/Object_SolidTile.hpp
		Game/GameObjects/Tiles/SlabTile/Object_SlabTile.cpp Game/GameObjects/Tiles/SlabTile/Object_SlabTile.hpp
		Game/GameObjects/Tiles/SolidTile/Object_SolidTile.cpp Game/GameObjects/Tiles/SolidTile/Object_SolidTile.hpp
		Game/GameObjects/Tiles/SolidTile/Object_EmptySolidTile.hpp Game/GameObjects/Tiles/SolidTile/Object_EmptySolidTile.cpp
		Game/GameObjects/Tiles/SlabTile/Object_SlabTile.cpp Game/GameObjects/Tiles/SlabTile/Object_SlabTile.hpp
		Game/GameObjects/Enemies/Hawk/Object_Hawk.cpp Game/GameObjects/Enemies/Hawk/Object_Hawk.hpp
		Game/GameObjects/Scenes/MainMenuScene/Object_MainMenuBackground.cpp
		Game/GameObjects/Scenes/SaveScene/Buttons/ExitButton/Object_ExitButton.cpp
		Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_PlayButton.cpp
		Game/GameObjects/Scenes/EtappeSelectionScene/Object_EtappeSelectionBackground.cpp Game/GameObjects/Scenes/EtappeSelectionScene/Object_EtappeSelectionBackground.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/Object_BackToMenuButton.cpp Game/GameObjects/Scenes/EtappeSelectionScene/Object_BackToMenuButton.hpp
		Game/GameObjects/Utils/Cheats/Object_Cheats.cpp Game/GameObjects/Utils/Cheats/Object_Cheats.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/Object_EtappeMarker.cpp Game/GameObjects/Scenes/EtappeSelectionScene/Object_EtappeMarker.hpp
		Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_ScoreboardButton.cpp Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_ScoreboardButton.hpp
		Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_SettingsButton.cpp Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_SettingsButton.hpp
		Game/GameObjects/Scenes/SaveScene/Buttons/DebugButton/Object_DebugButton.cpp Game/GameObjects/Scenes/SaveScene/Buttons/DebugButton/Object_DebugButton.hpp
		Game/GameObjects/Utils/LifeHeart/Object_LifeHeart.cpp Game/GameObjects/Utils/LifeHeart/Object_LifeHeart.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/Object_VictoryFlag.cpp Game/GameObjects/WorldObjects/VictoryFlag/Object_VictoryFlag.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/Behavior_VictoryFlag.cpp Game/GameObjects/WorldObjects/VictoryFlag/Behavior_VictoryFlag.hpp
		Game/GameObjects/Scenes/Etappes/EtappeOneScene/Object_EtappeOneText.cpp Game/GameObjects/Scenes/Etappes/EtappeOneScene/Object_EtappeOneText.hpp
		Game/GameObjects/Utils/FpsMeter/Object_FpsMeter.cpp Game/GameObjects/Utils/FpsMeter/Object_FpsMeter.hpp
		Game/GameObjects/Scenes/Etappes/Object_BackToEtappeSelectionButton.cpp Game/GameObjects/Scenes/Etappes/Object_BackToEtappeSelectionButton.hpp
		Game/GameObjects/WorldObjects/HealthPickup/Object_HealthPickup.cpp Game/GameObjects/WorldObjects/HealthPickup/Object_HealthPickup.hpp
		Game/GameObjects/Tiles/LavaTile/Object_LavaTile.cpp Game/GameObjects/Tiles/LavaTile/Object_LavaTile.hpp
		Game/GameObjects/Scenes/Etappes/Behavior_Etappe.cpp Game/GameObjects/Scenes/Etappes/Behavior_Etappe.hpp
		Game/GameObjects/Player/Behavior_Player.hpp Game/GameObjects/Player/Behavior_Player.cpp
		Game/GameObjects/Scenes/SaveScene/Buttons/ExitButton/Behavior_QuitGame.hpp Game/GameObjects/Scenes/SaveScene/Buttons/ExitButton/Behavior_QuitGame.cpp
		Game/GameObjects/Scenes/EtappeSelectionScene/Behavior_EtappeMarker.cpp Game/GameObjects/Scenes/EtappeSelectionScene/Behavior_EtappeMarker.hpp
		Game/GameObjects/Scenes/Behavior_SwitchSceneButton.hpp Game/GameObjects/Scenes/Behavior_SwitchSceneButton.cpp
		Game/GameObjects/Enemies/Hawk/Behavior_Predator/Behavior_Predator_Hawk.hpp Game/GameObjects/Enemies/Hawk/Behavior_Predator/Behavior_Predator_Hawk.cpp
		Game/GameObjects/Utils/LifeHeart/Behavior_LifeHeart.cpp Game/GameObjects/Utils/LifeHeart/Behavior_LifeHeart.hpp
		Game/GameObjects/Utils/Cheats/Behavior_Cheats.cpp Game/GameObjects/Utils/Cheats/Behavior_Cheats.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/Behavior_VictoryFlag.cpp Game/GameObjects/WorldObjects/VictoryFlag/Behavior_VictoryFlag.hpp
		Game/GameObjects/Enemies/Goat/Behavior_Goat.cpp Game/GameObjects/Enemies/Goat/Behavior_Goat.hpp
		Game/GameObjects/Scenes/SaveScene/Buttons/DebugButton/Behavior_DebugButton.cpp Game/GameObjects/Scenes/SaveScene/Buttons/DebugButton/Behavior_DebugButton.hpp
		Game/GameObjects/Utils/FpsMeter/Behavior_FpsMeter.cpp Game/GameObjects/Utils/FpsMeter/Behavior_FpsMeter.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Behavior_PauseActivation.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Behavior_PauseActivation.hpp
		Game/GameObjects/Scenes/VictoryScene/Behavior_VictoryScreen.cpp Game/GameObjects/Scenes/VictoryScene/Behavior_VictoryScreen.hpp
		Game/GameObjects/WorldObjects/HealthPickup/Behavior_HealthPickup.cpp Game/GameObjects/WorldObjects/HealthPickup/Behavior_HealthPickup.hpp
		Game/GameObjects/Tiles/LavaTile/Behavior_LavaTile.cpp Game/GameObjects/Tiles/LavaTile/Behavior_LavaTile.hpp
		Game/GameObjects/Tiles/Object_Tile.hpp Game/GameObjects/Tiles/Object_Tile.cpp
		Game/Scenes/Templates/SceneTemplate_Etappe.cpp Game/Scenes/Templates/SceneTemplate_Etappe.hpp
		Game/Scenes/Menus/Scene_GameOverMenu.cpp
		Game/GameObjects/Player/Animator_PlayerWalking.cpp Game/GameObjects/Player/Animator_PlayerWalking.hpp
		Game/GameObjects/Player/Sprites/Sprite_PlayerIdle.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerIdle.hpp
		Game/GameObjects/Player/Sprites/Sprite_PlayerMove1.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerMove1.hpp
		Game/GameObjects/Player/Sprites/Sprite_PlayerMove3.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerMove3.hpp
		Game/GameObjects/Player/Sprites/Sprite_PlayerJump.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerJump.hpp
		Game/GameObjects/Player/Sprites/Sprite_PlayerMove2.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerMove2.hpp
		Game/GameObjects/Player/Sounds/Sound_Jump.cpp Game/GameObjects/Player/Sounds/Sound_Jump.hpp
		Game/GameObjects/Player/Sounds/Sound_Walk.cpp Game/GameObjects/Player/Sounds/Sound_Walk.hpp
		Game/GameObjects/Player/Sounds/Sound_WalkAlt.cpp Game/GameObjects/Player/Sounds/Sound_WalkAlt.hpp
		Game/GameObjects/Player/Sounds/Sound_Oof.cpp Game/GameObjects/Player/Sounds/Sound_Oof.hpp
		Game/GameObjects/Player/Sounds/Sound_Death.cpp Game/GameObjects/Player/Sounds/Sound_Death.hpp
		Game/GameObjects/Scenes/Script_SwitchSceneButton.cpp Game/GameObjects/Scenes/Script_SwitchSceneButton.hpp
		Game/GameObjects/Scenes/SaveScene/Buttons/ExitButton/Script_QuitGame.cpp Game/GameObjects/Scenes/SaveScene/Buttons/ExitButton/Script_QuitGame.hpp
		Game/GameObjects/Scenes/EtappeSelectionScene/Script_EtappeMarkerConfigurator.cpp Game/GameObjects/Scenes/EtappeSelectionScene/Script_EtappeMarkerConfigurator.hpp
		Game/GameObjects/Player/Script_PlayerMovement.cpp Game/GameObjects/Player/Script_PlayerMovement.hpp
		Game/GameObjects/Enemies/Hawk/Behavior_Predator/Script_Predator_Hawk.cpp Game/GameObjects/Enemies/Hawk/Behavior_Predator/Script_Predator_Hawk.hpp
		Game/GameObjects/Utils/FpsMeter/Script_FpsMeter.cpp Game/GameObjects/Utils/FpsMeter/Script_FpsMeter.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_Pause.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_Pause.hpp
		Game/GameObjects/Utils/LifeHeart/Script_LifeHeart.cpp Game/GameObjects/Utils/LifeHeart/Script_LifeHeart.hpp
		Game/GameObjects/Scenes/Etappes/Script_LifeInit.cpp Game/GameObjects/Scenes/Etappes/Script_LifeInit.hpp
		Game/GameObjects/Utils/Cheats/Script_Cheats.cpp Game/GameObjects/Utils/Cheats/Script_Cheats.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/Script_VictoryFlag.cpp
		Game/GameObjects/Player/Script_Damage.cpp
		Game/GameObjects/Utils/Cheats/Behavior_Cheats.cpp
		Game/GameObjects/Utils/Cheats/Script_Cheats.cpp
		Game/GameObjects/WorldObjects/VictoryFlag/Object_VictoryFlag.cpp
		Game/GameObjects/Scenes/Behavior_GameState.cpp Game/GameObjects/Scenes/EtappeEndScene/Script_GameState.cpp
		Game/GameObjects/Scenes/Object_GameStateManager.cpp
		Game/GameObjects/Scenes/EtappeEndScene/Object_VictoryScreenManager.cpp
		Game/GameObjects/Scenes/EtappeEndScene/Object_DefeatBackground.cpp Game/GameObjects/Scenes/EtappeEndScene/Object_SelectEtappeButton.cpp
		Game/GameObjects/Scenes/EtappeEndScene/Object_NextEtappeButton.cpp Game/GameObjects/Scenes/EtappeEndScene/Object_RetryButton.cpp
		Game/GameObjects/Utils/Cheats/Script_Cheats.cpp Game/GameObjects/Utils/Cheats/Script_Cheats.hpp
		Game/GameObjects/WorldObjects/VictoryFlag/Script_VictoryFlag.cpp Game/GameObjects/WorldObjects/VictoryFlag/Script_VictoryFlag.hpp
		Game/GameObjects/Player/Script_Damage.cpp Game/GameObjects/Player/Script_Damage.hpp
		Game/GameObjects/Enemies/Goat/Script_Goat.cpp Game/GameObjects/Enemies/Goat/Script_Goat.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_SummonGoat.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_SummonGoat.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_DamageCheat.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_DamageCheat.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_AdjustSpeed.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_AdjustSpeed.hpp
		Game/GameObjects/WorldObjects/HealthPickup/Script_Heal.cpp Game/GameObjects/WorldObjects/HealthPickup/Script_Heal.hpp
		Game/GameObjects/Tiles/LavaTile/Script_LavaTile.cpp Game/GameObjects/Tiles/LavaTile/Script_LavaTile.hpp
		Game/GameObjects/Scenes/SaveScene/Buttons/DebugButton/Script_DebugToggle.cpp Game/GameObjects/Scenes/SaveScene/Buttons/DebugButton/Script_DebugToggle.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_PauseActivation.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_PauseActivation.hpp
		Game/GameObjects/Scenes/VictoryScene/Script_IncreaseEtappeCount.cpp Game/GameObjects/Scenes/VictoryScene/Script_IncreaseEtappeCount.hpp
		Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_BeatLevel.cpp Game/GameObjects/Utils/Cheats/CheatsLibrary/Script_BeatLevel.hpp
        Game/GameObjects/Enemies/Snake/Object_Snake.cpp Game/GameObjects/Enemies/Snake/Object_Snake.hpp Game/GameObjects/Enemies/Snake/Behavior_Snake.cpp Game/GameObjects/Enemies/Snake/Behavior_Snake.hpp Game/GameObjects/Enemies/Snake/Script_Snake.cpp Game/GameObjects/Enemies/Snake/Script_Snake.hpp
		Game/GameObjects/Scenes/Etappes/EtappeTwoScene/Object_EtappeTwoText.cpp Game/GameObjects/Scenes/Etappes/EtappeTwoScene/Object_EtappeTwoText.hpp
		Game/GameObjects/Utils/Timer/Object_Timer.cpp Game/GameObjects/Utils/Timer/Object_Timer.hpp
		Game/GameObjects/Utils/Timer/Behavior_Timer.cpp Game/GameObjects/Utils/Timer/Behavior_Timer.hpp
		Game/GameObjects/Utils/Timer/Object_TimerLine.cpp Game/GameObjects/Utils/Timer/Object_TimerLine.hpp
		Game/GameObjects/Utils/Timer/Behavior_TimeLine.cpp Game/GameObjects/Utils/Timer/Behavior_TimeLine.hpp
		Game/GameObjects/Utils/Timer/Script_TimerLine.cpp Game/GameObjects/Utils/Timer/Script_TimerLine.hpp
		Game/GameObjects/Utils/Timer/Script_Timer.cpp Game/GameObjects/Utils/Timer/Script_Timer.cpp Game/GameObjects/WorldObjects/Trash/Object_Trash.cpp Game/GameObjects/WorldObjects/Trash/Object_Trash.hpp Game/GameObjects/WorldObjects/Trash/Behavior_Trash.cpp Game/GameObjects/WorldObjects/Trash/Behavior_Trash.hpp Game/GameObjects/WorldObjects/Trash/Script_Trash.cpp Game/GameObjects/WorldObjects/Trash/Script_Trash.hpp Game/GameObjects/Utils/TrashCounter/Object_TrashCounter.cpp Game/GameObjects/Utils/TrashCounter/Object_TrashCounter.hpp Game/GameObjects/Utils/TrashCounter/Behavior_TrashCounter.cpp Game/GameObjects/Utils/TrashCounter/Behavior_TrashCounter.hpp Game/GameObjects/Utils/TrashCounter/Script_TrashCounter.cpp Game/GameObjects/Utils/TrashCounter/Script_TrashCounter.hpp
		Game/GameObjects/Utils/Timer/Script_Timer.cpp Game/GameObjects/Utils/Timer/Script_Timer.cpp Game/Scenes/Etappes/Scene_EtappeThree.cpp Game/Scenes/Etappes/Scene_EtappeThree.hpp
		Game/GameObjects/Scenes/Etappes/EtappeThreeScene/Object_EtappeThreeManager.cpp Game/GameObjects/Scenes/Etappes/EtappeThreeScene/Object_EtappeThreeManager.hpp Game/Scenes/Etappes/Scene_EtappeFour.cpp Game/Scenes/Etappes/Scene_EtappeFour.hpp Game/GameObjects/Scenes/Etappes/EtappeFourScene/Object_EtappeFourManager.cpp Game/GameObjects/Scenes/Etappes/EtappeFourScene/Object_EtappeFourManager.hpp Game/GameObjects/Enemies/Snowball/Object_Snowball.cpp Game/GameObjects/Enemies/Snowball/Object_Snowball.hpp Game/GameObjects/Enemies/Snowball/Behavior_Snowball.cpp Game/GameObjects/Enemies/Snowball/Behavior_Snowball.hpp Game/GameObjects/Enemies/Snowball/Script_Snowball.cpp Game/GameObjects/Enemies/Snowball/Script_Snowball.hpp
		Game/GameObjects/Scenes/Etappes/EtappeThreeScene/Object_EtappeThreeManager.cpp Game/GameObjects/Scenes/Etappes/EtappeThreeScene/Object_EtappeThreeManager.hpp
		Game/Scenes/Etappes/Scene_EtappeFive.cpp Game/Scenes/Etappes/Scene_EtappeFive.hpp Game/GameObjects/Scenes/Etappes/EtappeFiveScene/Object_EtappeFiveManager.cpp Game/GameObjects/Scenes/Etappes/EtappeFiveScene/Object_EtappeFiveManager.hpp Game/GameObjects/Tiles/WallTile/Object_WallTile.cpp Game/GameObjects/Tiles/WallTile/Object_WallTile.hpp
		Game/Scenes/Menus/Scene_SaveFileMenu.cpp Game/Scenes/Menus/Scene_SaveFileMenu.hpp
		Game/GameObjects/Scenes/SaveScene/Object_SavesManager.cpp Game/GameObjects/Scenes/SaveScene/Object_SavesManager.hpp Game/GameObjects/Scenes/SaveScene/Behavior_SavesManager.cpp Game/GameObjects/Scenes/SaveScene/Behavior_SavesManager.hpp
		Game/GameObjects/Scenes/SaveScene/Script_LoadSaves.cpp Game/GameObjects/Scenes/SaveScene/Script_LoadSaves.hpp Game/GameObjects/Scenes/SaveScene/SaveFile/Object_SaveFile.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Object_SaveFile.hpp Game/GameObjects/Player/Sprites/Sprite_PlayerWin.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerWin.hpp Game/GameObjects/Player/Sprites/Sprite_PlayerFront.cpp Game/GameObjects/Player/Sprites/Sprite_PlayerFront.hpp
		Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Sprite_PlayButton.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Sprite_PlayButton.hpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Sprite_DeleteButton.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Sprite_DeleteButton.hpp
		Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Object_PlaySaveButton.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Object_PlaySaveButton.hpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Object_DeleteSaveButton.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Object_DeleteSaveButton.hpp Game/Scenes/Music/Music_SmoothGroove.cpp Game/Scenes/Music/Music_SmoothGroove.hpp
		Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Behavior_PlaySave.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Behavior_PlaySave.hpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Script_PlaySave.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/PlaySaveButton/Script_PlaySave.hpp
		Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Behavior_DeleteSave.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Behavior_DeleteSave.hpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Script_DeleteSave.cpp Game/GameObjects/Scenes/SaveScene/SaveFile/Buttons/DeleteSaveButton/Script_DeleteSave.hpp Game/Scenes/Menus/Sounds/Sound_Delete.cpp Game/Scenes/Menus/Sounds/Sound_Delete.hpp
		Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_BackToSaveScreenButton.cpp Game/GameObjects/Scenes/MainMenuScene/Buttons/Object_BackToSaveScreenButton.hpp
		Game/Scenes/Etappes/Scene_EtappeFive.cpp Game/Scenes/Etappes/Scene_EtappeFive.hpp Game/GameObjects/Scenes/Etappes/EtappeFiveScene/Object_EtappeFiveManager.cpp Game/GameObjects/Scenes/Etappes/EtappeFiveScene/Object_EtappeFiveManager.hpp Game/GameObjects/Tiles/WallTile/Object_WallTile.cpp Game/GameObjects/Tiles/WallTile/Object_WallTile.hpp
		Game/GameObjects/Utils/Decor/Object_Cloud.cpp Game/GameObjects/Utils/Decor/Object_Cloud.hpp Game/GameObjects/Utils/Decor/Behavior_Cloud.cpp Game/GameObjects/Utils/Decor/Behavior_Cloud.hpp Game/GameObjects/Utils/Decor/Script_Cloud.cpp Game/GameObjects/Utils/Decor/Script_Cloud.hpp Game/GameObjects/Utils/Decor/Advertising/Object_Aeroplane.cpp Game/GameObjects/Utils/Decor/Advertising/Object_Aeroplane.hpp Game/GameObjects/Utils/Decor/Advertising/Object_Banner.cpp Game/GameObjects/Utils/Decor/Advertising/Object_Banner.hpp Game/GameObjects/Utils/Decor/Advertising/Object_AdvertisingPane.cpp Game/GameObjects/Utils/Decor/Advertising/Object_AdvertisingPane.hpp Game/GameObjects/Utils/Decor/Advertising/Script_AeroplaneFlight.cpp Game/GameObjects/Utils/Decor/Advertising/Script_AeroplaneFlight.hpp Game/GameObjects/Utils/Decor/Advertising/Behavior_Aeroplane.cpp Game/GameObjects/Utils/Decor/Advertising/Behavior_Aeroplane.hpp Game/GameObjects/Utils/Decor/Advertising/Animator_BannerFlutter.cpp Game/GameObjects/Utils/Decor/Advertising/Animator_BannerFlutter.hpp
		Game/GameObjects/Scenes/SaveScene/Decor/Sprite_SaveBackground.cpp Game/GameObjects/Scenes/SaveScene/Decor/Sprite_SaveBackground.hpp Game/GameObjects/Scenes/SaveScene/Decor/Object_CoolGoat.cpp Game/GameObjects/Scenes/SaveScene/Decor/Object_CoolGoat.hpp Game/Scenes/Menus/Utils/Animator_CoolGoat.cpp Game/Scenes/Menus/Utils/Animator_CoolGoat.hpp Game/GameObjects/Scenes/SaveScene/Decor/Sprite_CoolGoat1.cpp Game/GameObjects/Scenes/SaveScene/Decor/Sprite_CoolGoat1.hpp Game/GameObjects/Scenes/SaveScene/Decor/Sprite_CoolGoat2.cpp Game/GameObjects/Scenes/SaveScene/Decor/Sprite_CoolGoat2.hpp
		Game/GameObjects/WorldObjects/Trash/Animator_Trash.cpp Game/GameObjects/WorldObjects/Trash/Animator_Trash.hpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash0.cpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash0.hpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash1.cpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash1.hpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash2.cpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash2.hpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash3.cpp Game/GameObjects/Utils/TrashCounter/Sprites/Sprite_Trash3.hpp
        Game/GameObjects/Enemies/Hawk/Behavior_Idle/Behavior_Idle_Hawk.cpp Game/GameObjects/Enemies/Hawk/Behavior_Idle/Behavior_Idle_Hawk.hpp Game/GameObjects/Enemies/Hawk/Behavior_Idle/Script_Idle_Hawk.cpp Game/GameObjects/Enemies/Hawk/Behavior_Idle/Script_Idle_Hawk.hpp)

target_link_libraries(Mount_Everestimate GOAT_Engine SDL2main)

add_executable(engine_tests "Tests/_Test.cpp" Tests/AnimatorHelperTest.cpp)
target_link_libraries(engine_tests GOAT_Engine SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer)

enable_testing()
# Place all necessary dlls and assets in build folder
add_custom_command(TARGET Mount_Everestimate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/DLLs
        ${PROJECT_SOURCE_DIR}/Game/Resources
        $<TARGET_FILE_DIR:Mount_Everestimate>)