cmake_minimum_required(VERSION 3.10)

project(cascadia-server)

set(SOURCES src/main.cpp # Add you other source files here, simply one per line
)

add_executable(cascadia-server ${SOURCES})
target_include_directories(cascadia-server PRIVATE include)

# Set cpp standard to 20
set_target_properties(cascadia-server PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS
                                                                 OFF)
# Enable warnings
if(MSVC)
  target_compile_options(cascadia-server PRIVATE /W4)
else()
  target_compile_options(cascadia-server PRIVATE -Wall -Wextra -Wshadow)
endif()

# Add dependencies
set(FRAMEWORK_GIT_FOLDER
    "framework/"
    CACHE STRING "Set to the framework git directory")
add_subdirectory(${FRAMEWORK_GIT_FOLDER} "framework")

target_link_libraries(cascadia-server PRIVATE OOP1_framework)
