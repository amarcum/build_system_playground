#Set the minimum version of CMake. I have set this to 3.1 as it supports 
# CXX 11 and 14 out of the box. CXX 17 can be used by setting the CXX Flags
cmake_minimum_required (VERSION 3.1)

include(project.cmake)

# Set the project name
project (${PROJECT_NAME})

#compiler options setup
#set(CMAKE_CXX_STANDARD 14)
option(MULTITHREAD_SUPPORT_ENABLED "Multithreaded Support Enabled" TRUE)
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++1z" )

#declare library object to be built
add_library(${PROJECT_NAME} SHARED src/${PROJECT_NAME}/main.cpp)

# Enable testing modules
enable_testing()

# Use GTest as the Test engine
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API        
documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
         message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    message("Doxygen build started.")

    add_custom_target(doc
                      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
                      COMMENT "Generating API documentation with Doxygen"
                      )
    
    add_custom_target(doc-clean
                      COMMAND rm -rf ${CMAKE_CURRENT_SOURCE_DIR}/doc/*
                      
                      )

   install(DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/doc/html DESTINATION share/doc)
endif()



# Create Test Executable. CMake allows one to create multiple test executables if 
# one wants to break down the testing by module
add_executable(${PROJECT_NAME}_test test/simple_test.cpp)
target_link_libraries(${PROJECT_NAME}_test ${GTEST_BOTH_LIBRARIES})

find_program( VALGRIND valgrind )

if(VALGRIND)
    add_custom_target(ci
        COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes $<TARGET_FILE:${PROJECT_NAME}_test>)
endif()

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
set(CPACK_PACKAGE_VENDOR "Cybercritter Software")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)