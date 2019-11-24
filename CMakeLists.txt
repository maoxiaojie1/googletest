cmake_minimum_required(VERSION 3.4.1)

set(PRO_NAME "googleTest")
set(EXE_NAME "test_0")

project(${PRO_NAME})

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_CXX_FLAGS "-std=c++11")
file(GLOB SRC_LIST "test/src/*.cpp")

set(include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_SOURCE_DIR}/test/include")

include_directories("${include_dir}")
#add_library(${PRO_NAME} ${SRC_LIST})
link_libraries( ${PROJECT_SOURCE_DIR}/lib/libgtest.a 
                ${PROJECT_SOURCE_DIR}/lib/libgtest_main.a
                ${PROJECT_SOURCE_DIR}/lib/libgmock.a
                ${PROJECT_SOURCE_DIR}/lib/libgmock_main.a
              )

find_package(Threads)
add_executable(${EXE_NAME} ${SRC_LIST})
target_link_libraries(${EXE_NAME}  ${CMAKE_THREAD_LIBS_INIT} 
                                   ${PROJECT_SOURCE_DIR}/lib/libgtest.a
                                   ${PROJECT_SOURCE_DIR}/lib/libgtest_main.a
                                   ${PROJECT_SOURCE_DIR}/lib/libgmock.a
                                   ${PROJECT_SOURCE_DIR}/lib/libgmock_main.a
                                   )