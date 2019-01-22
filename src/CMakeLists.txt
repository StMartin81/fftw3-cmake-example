cmake_minimum_required(VERSION 3.10.2)

project(test-fftw3)
add_executable (${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} fftw3 fftw3_threads)
