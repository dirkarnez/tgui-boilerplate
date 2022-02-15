cmake_minimum_required(VERSION 3.19)

project(tgui-boilerplate)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED PATHS ${SFML_ROOT})

set(TGUI_STATIC_LIBRARIES TRUE)
find_package(tgui 0.9.3 EXACT REQUIRED PATHS ${TGUI_ROOT})

if (tgui_FOUND)
    message("tgui found")
else (tgui_FOUND)
    message("tgui not found")
endif()

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -Wl,--subsystem,windows")

add_executable(${PROJECT_NAME}
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} sfml-graphics tgui)