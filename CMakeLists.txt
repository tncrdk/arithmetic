# arithmetic_benchmark/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(arithmetic_benchmark VERSION 1.0.0 LANGUAGES CXX)
# include(CMakePrintHelpers)

# Create the shared library
add_library(arithmetic_benchmark SHARED
    arithmetic_benchmark.cpp
)

# Specify include directories for the library itself
target_include_directories(arithmetic_benchmark PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
# cmake_print_variables(CMAKE_CURRENT_SOURCE_DIR)

# Install rules for the library
install(TARGETS arithmetic_benchmark
    EXPORT arithmetic_benchmark_targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin # For Windows DLLs
)

# Install headers
install(FILES
    arithmetic_benchmark.h
    DESTINATION include
)

# Generate and install the package configuration file
# This is crucial for find_package to work correctly
install(EXPORT arithmetic_benchmark_targets
    FILE arithmetic_benchmarkConfig.cmake
    NAMESPACE arithmetic_benchmark::
    DESTINATION lib/cmake/arithmetic_benchmark
)

# Create a package configuration file for find_package(arithmetic_benchmark)
# This content will be written to arithmetic_benchmarkConfigVersion.cmake and lib_aConfig.cmake during install
# For simple cases, arithmetic_benchmarkConfig.cmake might just contain include(lib_aTargets.cmake)
# For more complex cases, you might generate it with configure_file
# Example simplified content for find_package(arithmetic_benchmark CONFIG)
set(arithmetic_benchmark_VERSION ${PROJECT_VERSION})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/arithmetic_benchmarkConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/arithmetic_benchmarkConfig.cmake @ONLY
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/arithmetic_benchmarkConfig.cmake
    DESTINATION lib/cmake/arithmetic_benchmark
)
