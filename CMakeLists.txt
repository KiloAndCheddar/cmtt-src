cmake_minimum_required(VERSION 3.16)

project(CMTT LANGUAGES CXX)

# Set the C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disables GNU extensions to ensure strict compliance

# Recursively grab ALL .cpp files inside the src/ folder automatically
#file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin
)

# Tell CMake to make an executable out of all those discovered sources
add_executable(cmtt ${SOURCES})

if(MSVC)
    target_compile_options(cmtt PRIVATE /W4)
else()
    target_compile_options(cmtt PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        #-Werror
    )
endif()

# Tell the compiler where it can find header files automatically
target_include_directories(cmtt PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)
