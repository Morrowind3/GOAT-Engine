cmake_minimum_required(VERSION 3.16)
project(GOAT_Engine)

set(CMAKE_CXX_STANDARD 17)

SET(MINGW_STATIC_FLAGS "-static-libgcc -static-libstdc++")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MINGW_STATIC_FLAGS}")

set(SDL2_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2-2.0.16/include")
set(SDL2_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2-2.0.16/lib/x86")
set(SDL2_TTF_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_TTF-2.0.15/include")
set(SDL2_TTF_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_TTF-2.0.15/lib/x86")
set(SDL2_IMAGE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_IMAGE-2.0.5/include")
set(SDL2_IMAGE_LIB_DIR ${PROJECT_SOURCE_DIR}/Libraries/SDL2_IMAGE-2.0.5/lib/x86)
set(SDL2_MIXER_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_MIXER-2.0.4/include")
set(SDL2_MIXER_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SDL2_MIXER-2.0.4/lib/x86")
set(BOX2D_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/BOX2D/include")
set(BOX2D_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/BOX2D/lib")
set(SQLITE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Libraries/SQLite/include")
set(SQLITE_LIB_DIR "${PROJECT_SOURCE_DIR}/Libraries/SQLite/lib")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR} ${SQLITE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_TTF_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_MIXER_LIB_DIR} ${BOX2D_LIB_DIR} ${SQLITE_LIB_DIR})

add_library(GOAT_Engine STATIC
        "Engine/API/GameObjects/GameComponents/GameComponent.hpp" "Engine/API/GameObjects/GameComponents/GameComponent.cpp"
        "Engine/API/GameObjects/GameComponents/Render/Sprite.hpp" "Engine/API/GameObjects/GameComponents/Render/Sprite.cpp"
        "Engine/API/GameObjects/Transform.hpp" "Engine/API/GameObjects/Transform.cpp"
        "Engine/API/GameObjects/Point.hpp" "Engine/API/GameObjects/Point.cpp"
        "Engine/API/GameObjects/GameObject.hpp" "Engine/API/GameObjects/GameObject.cpp"
        "Engine/API/Scene.hpp" "Engine/API/Scene.cpp"
        "Engine/SceneManager.hpp" "Engine/SceneManager.cpp"
        "Engine/Systems/RenderingSystem.hpp" "Engine/Systems/RenderingSystem.cpp"
        "Engine/Systems/System.hpp" "Engine/Systems/System.cpp"
        "Engine/Engine.hpp" "Engine/Engine.cpp"
        Engine/Systems/Apis/Implementations/RendererImpl.cpp Engine/Systems/Apis/Implementations/RendererImpl.hpp
        Engine/Systems/Apis/Implementations/Managers/Texture.cpp Engine/Systems/Apis/Implementations/Managers/Texture.hpp
        Engine/Systems/Apis/RendererApi.cpp Engine/Systems/Apis/RendererApi.hpp
        Engine/Systems/Apis/Implementations/Managers/TextureManager.cpp Engine/Systems/Apis/Implementations/Managers/TextureManager.hpp
        Engine/Systems/ScriptSystem.cpp Engine/Systems/ScriptSystem.hpp Engine/API/GameObjects/GameComponents/Script/Script.hpp
        Engine/Systems/Apis/Implementations/AudioImpl.cpp Engine/Systems/Apis/Implementations/AudioImpl.hpp
        Engine/Systems/Apis/AudioApi.cpp Engine/Systems/Apis/AudioApi.hpp
        Engine/Systems/AudioSystem.cpp Engine/Systems/AudioSystem.hpp
        Engine/API/GameObjects/GameComponents/Script/Script.cpp Engine/API/GameObjects/GameComponents/Script/Behavior.cpp
        Engine/API/GameObjects/GameComponents/Script/Behavior.hpp
        Engine/Systems/Apis/RendererApi.cpp Engine/Systems/Apis/RendererApi.hpp Engine/Utilities/Input.cpp)

add_executable(Mount_Everestimate
        "Game/Game.cpp"
        "Game/GameScenes.hpp"
        # Scenes
        "Game/Scenes/ExampleScene.hpp"
        # Objects
        "Game/GameObjects/Goat.hpp" Game/Behaviors/Scripts/GoatTestScript.cpp Game/Behaviors/Scripts/GoatTestScript.hpp Game/GameObjects/Goat.cpp
        Game/Behaviors/GoatBehavior.hpp Game/Behaviors/Scripts/AdditionalGoatTestScript.cpp Game/Behaviors/Scripts/AdditionalGoatTestScript.hpp)

target_link_libraries(Mount_Everestimate GOAT_Engine SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer box2d sqlite3)

add_executable(engine_tests "Engine/Tests/SampleTest.cpp")
target_link_libraries(engine_tests GOAT_Engine SDL2main SDL2 SDL2_ttf SDL2_image SDL2_mixer box2d)

add_executable(game_tests "Game/Tests/PlayerTest.cpp")
target_link_libraries(engine_tests GOAT_Engine)
enable_testing()
# Place all necessary dlls and assets in build folder
add_custom_command(TARGET Mount_Everestimate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/DLLs
        ${PROJECT_SOURCE_DIR}/Game/Resources
        $<TARGET_FILE_DIR:Mount_Everestimate>)