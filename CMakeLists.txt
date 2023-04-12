cmake_minimum_required(VERSION 3.05)
project(facerec_ncnn)

set(CMAKE_CXX_STANDARD 14)

set(ncnn_DIR "/home/duongtt/tencent/ncnn/build/install/lib/cmake/ncnn")
set(OpenCV_DIR "/home/duongtt/app/lib/cmake/opencv4")

find_package(ncnn REQUIRED)

find_package(OpenCV REQUIRED)

include_directories(
    ./inc
)

add_executable(${PROJECT_NAME} ./main.cpp ./src/FaceMeshService.cpp ./inc/FaceMeshService.h)

target_link_libraries(${PROJECT_NAME} ncnn ${OpenCV_LIBS})
