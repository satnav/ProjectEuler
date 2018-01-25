# Specify include directories
include_directories(${CMAKE_SOURCE_DIR}/common/include)
include_directories(${CMAKE_SOURCE_DIR}/problem17/include)

# Make the executable
add_executable(problem17 main.cpp NumberTranslator.cpp)

# Link with the library
target_link_libraries(problem17 common)
