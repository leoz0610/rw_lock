cmake_minimum_required(VERSION 3.8)
project(rw_lock)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cache.cpp cache.h test_cache.cpp test_cache.h workers.cpp workers.h utils/stop_watch.cpp utils/stop_watch.h)
add_executable(rw_lock main.cpp ${SOURCE_FILES})


# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
set(UNITTESTS_SOURCE_FILES unit_tests/stop_watch.t.cpp unit_tests/test_cache.t.cpp)
add_executable(RWLockUnitTests ${SOURCE_FILES} ${UNITTESTS_SOURCE_FILES})
target_link_libraries(RWLockUnitTests gtest_main)
add_test(NAME RWLockUnitTests COMMAND RWLockUnitTests)