#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <cmath>

namespace arithmetic_benchmark {

// Function to perform a large number of integer operations
void cpu_integer_benchmark(long iterations) {
    long long sum = 0;
    for (long i = 0; i < iterations; ++i) {
        sum += (i * 3) / 7 + (i % 5);
        // Prevent compiler from optimizing away the loop completely
        // by making 'sum' dependent on 'i' and using it
        if (i % 1000000 == 0) {
            volatile long long temp = sum; // Volatile to ensure 'sum' is actually accessed
        } }
}

// Function to perform a large number of floating-point operations
void cpu_float_benchmark(long iterations) {
    double result = 1.0;
    for (long i = 0; i < iterations; ++i) {
        result = result * 1.000000001 + std::sin(static_cast<double>(i) * 0.00001);
        // Prevent compiler from optimizing away
        if (i % 1000000 == 0) {
            volatile double temp = result;
        }
    }
}

void run() {
    long num_iterations = 500000000; // Adjust as needed for desired duration

    std::cout << "------------------------" << std::endl;

    // --- Integer Benchmark ---
    std::cout << "Benchmarking CPU Integer Operations (" << num_iterations << " iterations)..." << std::endl;
    auto start_int = std::chrono::high_resolution_clock::now();
    cpu_integer_benchmark(num_iterations);
    auto end_int = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_int = end_int - start_int;
    std::cout << "Integer operations time: " << duration_int.count() << " seconds" << std::endl;

    // --- Floating-Point Benchmark ---
    std::cout << "\nBenchmarking CPU Floating-Point Operations (" << num_iterations << " iterations)..." << std::endl;
    auto start_float = std::chrono::high_resolution_clock::now();
    cpu_float_benchmark(num_iterations);
    auto end_float = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_float = end_float - start_float;
    std::cout << "Floating-point operations time: " << duration_float.count() << " seconds" << std::endl;

    std::cout << "------------------------\n" << std::endl;
}

} // namespace arithmetic_benchmark

