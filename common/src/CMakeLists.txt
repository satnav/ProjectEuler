# Specify the include directory
include_directories(${CMAKE_SOURCE_DIR}/common/include)

# Make the library
add_library(common AutoTimer.cpp BigInteger.cpp Math.cpp)
