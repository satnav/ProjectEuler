# Specify include directories
include_directories(${CMAKE_SOURCE_DIR}/common/include)

# Make the executable
add_executable(problem16 main.cpp)

# Link with the library
target_link_libraries(problem16 common)
