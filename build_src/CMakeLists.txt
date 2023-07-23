cmake_minimum_required(VERSION 3.0.0)
project(IMAGE_PROCESSING_SYSTEM VERSION 0.1.0
        LANGUAGES CXX)
        
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_INCLUDE_DIRS})

add_executable(main main.cpp image.cpp image_processing_system.cpp menu.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries( main  ${OpenCV_LIBS})


