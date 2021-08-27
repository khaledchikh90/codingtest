cmake_minimum_required(VERSION 3.0.0)
project(codingtest VERSION 0.1.0)

include(CTest)
enable_testing()
file(GLOB codingtest_SRC src/* demo/demo.cpp)
add_executable(codingtest ${codingtest_SRC})


find_package( OpenCV REQUIRED )
MESSAGE("OpenCV version : ${OpenCV_VERSION}")
include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries( codingtest ${OpenCV_LIBS} )



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)