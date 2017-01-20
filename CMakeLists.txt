cmake_minimum_required (VERSION 3.1)

project (build_system_playground)


#set(CMAKE_CXX_STANDARD 17)
option(MULTITHREAD_SUPPORT_ENABLED "Multithreaded Support Enabled" TRUE)
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++1z" )
add_library(build_system_playground SHARED src/build_system_playground/main.cpp)


enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(build_system_playground_test test/simple_test.cpp)
target_link_libraries(build_system_playground_test ${GTEST_BOTH_LIBRARIES})
add_test(AllTestsInBuildSystemPlaygroundTests build_system_playground_test)
