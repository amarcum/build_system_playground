#Set the minimum version of CMake. I have set this to 3.1 as it supports 
# CXX 11 and 14 out of the box. CXX 17 can be used by setting the CXX Flags
cmake_minimum_required (VERSION 3.1)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 4)

# Set the project name
project (build_system_playground)


#compiler options setup
#set(CMAKE_CXX_STANDARD 14)
option(MULTITHREAD_SUPPORT_ENABLED "Multithreaded Support Enabled" TRUE)
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++1z" )

#declare library object to be built
add_library(build_system_playground SHARED src/build_system_playground/main.cpp)

# Enable testing modules
enable_testing()

# Use GTest as the Test engine
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create Test Executable. CMake allows one to create multiple test executables if 
# one wants to break down the testing by module
add_executable(build_system_playground_test test/simple_test.cpp)
target_link_libraries(build_system_playground_test ${GTEST_BOTH_LIBRARIES})

# Add the tests to be run. This is what runs when ninja-build test or make test (if using
# GNU Make).
add_test(AllTestsInBuildSystemPlaygroundTests build_system_playground_test)

# Create a deployable installer. AKA: Packaging. We will use Red Hat Package Manager with CPack
# Whether to build on fedora
install(TARGETS build_system_playground LIBRARY DESTINATION lib64)
SET(VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME "build_system_playground")
set(CPACK_PACKAGE_CONTACT "Michael J Reid")
set(CPACK_PACKAGE_VENDOR "L3 Technologies")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)