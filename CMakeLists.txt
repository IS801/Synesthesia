#use a recent version of CMake
cmake_minimum_required(VERSION 3.15)

#the project is called asteroids
project(Synesthesia)

#the project contains an executable named testSFML that uses the following cpp files
add_executable(synesthesia src/main.cpp src/game.cpp src/game.hpp src/keyboard.cpp src/keyboard.hpp src/ParticleSystem.cpp src/ParticleSystem.hpp)

#create a folder named "cmake" at the top of your project and put the
#synesthesia.cmake file in it.  This line tells Cmake to look there for
#find____.cmake files
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

#this says find the graphics, window, and system libraries
#it uses the synesthesia.cmake file to do so and sets
#some variables ($SFML_LIBRARIES and SFML_INCLUDE_DIRECTORIES) that are
#used below
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

#tells Cmake that the synesthesia executable needs to be linked with SFML
target_link_libraries(synesthesia sfml-graphics sfml-audio)

#passes an option to clang when compiling to use recent c++ stuff
target_compile_options(synesthesia PUBLIC -std=c++17)
