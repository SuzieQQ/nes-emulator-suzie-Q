cmake_minimum_required (VERSION 3.2)
project(neSQ)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC "src/*.cpp" "src/*.h")
add_executable(neSQ ${SRC})

# Look up SDL2 and add include/lib dirs to it
set(SDL2_BUILDING_LIBRARY ON) # Don't find SDL2main lib
find_package(SDL2 REQUIRED)
include_directories(neSQ PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(neSQ PRIVATE ${SDL2_LIBRARIES})




