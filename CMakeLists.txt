cmake_minimum_required(VERSION 3.16)
project(CMTT LANGUAGES CXX) 
# we're not using C code

# Enforce strict C++17 compliance, error if unsupported, and strict portable ISO C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Recursively grab ALL .cpp files inside the src/ folder automatically
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
# Custom output folder lol
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin
)

# Tell CMake to make an executable out of all those discovered sources
add_executable(cmtt ${SOURCES})

# MSVC hack to mimic GCC flags
if(MSVC)
    target_compile_options(cmtt PRIVATE /W4 /WX)
else()
    target_compile_options(cmtt PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        # i might hate myself later :p
    )
endif()

# Tell the compiler where it can find header files automatically
target_include_directories(cmtt PRIVATE
    "${CMAKE_SOURCE_DIR}/src"
)
