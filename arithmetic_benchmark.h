#pragma once

namespace arithmetic_benchmark {
// Function to perform a large number of integer operations
void cpu_integer_benchmark(long iterations);

// Function to perform a large number of floating-point operations
void cpu_float_benchmark(long iterations);

void run();

} // namespace arithmetic_benchmark
