cmake_minimum_required(VERSION 3.10.2)

project(fftw3-cmake-example)

# see also: https://crascit.com/2015/07/25/cmake-gtest/
# Download and unpack FFTW3 at configure time
configure_file(${CMAKE_SOURCE_DIR}/CMakeLists.txt.in ${CMAKE_BINARY_DIR}/fftw3-download/CMakeLists.txt)

# Allow FFTW3 to be build with MinGW and export include directories for build interface
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" -A "${CMAKE_GENERATOR_PLATFORM}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/fftw3-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/fftw3-download" )

configure_file(${CMAKE_SOURCE_DIR}/CMakeLists.txt.fftw3 ${CMAKE_BINARY_DIR}/fftw3-src/CMakeLists.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/kalloc.c.fftw3 ${CMAKE_BINARY_DIR}/fftw3-src/kernel/kalloc.c COPYONLY)
message("configure_file(${CMAKE_SOURCE_DIR}/CMakeLists.txt.fftw3 ${CMAKE_BINARY_DIR}/fftw3-src/CMakeLists.txt COPYONLY)")
message("configure_file(${CMAKE_SOURCE_DIR}/kalloc.c.fftw3 ${CMAKE_BINARY_DIR}/fftw3-src/kernel/kalloc.c COPYONLY)")

# Add fftw3 directly to our build. This adds
# the following targets: fftw3
add_subdirectory("${CMAKE_BINARY_DIR}/fftw3-src"
                 "${CMAKE_BINARY_DIR}/fftw3-build")

add_subdirectory(src)
