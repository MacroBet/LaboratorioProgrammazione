cmake_minimum_required(VERSION 3.7)
project(PathFinding)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyWidget.h GameMap.h OptionMenu.h GameMap.cpp OptionMenu.cpp Button.cpp Button.h FindPathGraphic.cpp FindPathGraphic.h Update.h findpath.cpp stlastar.h fsa.h)
add_executable(PathFinding ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PathFinding ${SFML_LIBRARIES})
endif()