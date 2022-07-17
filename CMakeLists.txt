cmake_minimum_required(VERSION 3.1)

project(plane)



find_package(SFML COMPONENTS graphics window system REQUIRED)


add_executable(plane
               src/main.cpp
               src/Game.cpp
               src/Entity.cpp
               src/Aircraft.cpp
               src/Texture.cpp
               src/Resource.cpp
               src/Enemy.cpp
               #src/SceneNode.cpp
        )


target_include_directories(
    plane
    PRIVATE
    src
    .
)


target_link_libraries(plane
                sfml-graphics
                sfml-window
                sfml-system
                )
