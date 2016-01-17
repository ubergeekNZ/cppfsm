cmake_minimum_required (VERSION 2.8.11)
project (unittests CXX C ASM)

set (MAIN_PROJECT_PATH ${PROJECT_SOURCE_DIR}/../..)
set (SOURCE_PATH ${MAIN_PROJECT_PATH}/source)

# Set the build definitions
# SET(CMAKE_CXX_FLAGS "-g -O0 -DUNITTEST_DEBUG -std=gnu++11")
SET(CMAKE_CXX_FLAGS "-g -O0 -std=gnu++11")
SET(BUILD_DEFINITIONS_TARGET "")
SET(BUILD_DEFINITIONS_DEBUG "")
SET(BUILD_DEFINITIONS_RELEASE "")


SET(MOCKS_DIR ${CMAKE_CURRENT_LIST_DIR}/mocks)
SET(TESTS_DIR ${CMAKE_CURRENT_LIST_DIR}/tests)


# It's best to hide all the details of setting up the variable SRCS in a CMake
# macro. The macro can then be called in all the project CMake list files to add
# sources.
#
# The macro first computes the path of the source file relative to the project
# root for each argument. If the macro is invoked from inside a project sub
# directory the new value of the variable SRCS needs to be propagated to the
# parent folder by using the PARENT_SCOPE option.
#
# Source: http://stackoverflow.com/questions/7046956/populating-srcs-from-cmakelists-txt-in-subdirectories
macro (add_sources)
    file (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    foreach (_src ${ARGN})
        if (_relPath)
            list (APPEND SRCS "${_relPath}/${_src}")
        else()
            list (APPEND SRCS "${_src}")
        endif()
    endforeach()
    if (_relPath)
        # propagate to parent directory
        set (SRCS ${SRCS} PARENT_SCOPE)
    endif()
endmacro()

include_directories(${MOCKS_DIR}
                    ${TESTS_DIR})


########## Modules ##########
set(INCLUDES 
    ${CMAKE_CURRENT_LIST_DIR}/src
)

FILE(GLOB SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

include_directories(${INCLUDES})
add_sources(${SOURCES})

include_directories(${CMAKE_CURRENT_LIST_DIR})
link_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    ${CMAKE_PROJECT_NAME}
    main.cpp
    ${SRCS}
    ${TESTS_DIR}/AppFSMTests.cpp
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    gmock
    gtest
    pthread
)

add_custom_target(run DEPENDS ${CMAKE_PROJECT_NAME} COMMAND ./${CMAKE_PROJECT_NAME})