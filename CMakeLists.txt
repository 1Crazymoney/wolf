cmake_minimum_required(VERSION 3.14)
project(wolf)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/demonic)
find_package(Boost REQUIRED COMPONENTS filesystem)
add_executable(wolf src/main.cpp)
target_link_libraries(wolf demonic)
target_link_libraries(wolf Boost::filesystem)