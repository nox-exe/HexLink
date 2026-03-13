cmake_minimum_required(VERSION 3.15)
project(MyFltkProject)

set(FLTK_DIR "C:/Dev/libs/fltk/build") 
find_package(FLTK REQUIRED NO_MODULE)

add_executable(HexLink 
    src/invite_system.cpp 
    ui/gui.cpp
)

target_include_directories(HexLink PRIVATE src ui)

target_link_libraries(HexLink fltk)