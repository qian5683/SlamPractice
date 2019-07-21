cmake_minimum_required(VERSION 3.14)
project(SlamPractice)



set(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})




add_executable(BatchFileRename ch1_Batch_file_rename/main.cpp)
target_link_libraries(BatchFileRename ${OpenCV_LIBRARIES})

add_executable(eigenDemo ch2_Eigen/Demo.cpp )
add_executable(EigenPractice ch2_Eigen/EigenPractice )