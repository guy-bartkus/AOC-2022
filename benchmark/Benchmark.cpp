#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <Benchmark.h>

double median(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());

    if (vec.size() % 2 == 0) {
        int middle2 = vec.size() / 2;
        int middle1 = middle2 - 1;

        return (vec[middle1] + vec[middle2]) / 2.0;
    }

    return vec[vec.size()/2];
}

using namespace std::chrono;
void benchmark(void (*func)(), int num_runs) {
    std::vector<int> times;

    for (int i = 0; i < num_runs; i++) {
        high_resolution_clock::time_point start = high_resolution_clock::now();
        func();
        high_resolution_clock::time_point end = high_resolution_clock::now();
        int time = duration_cast<microseconds>(end - start).count();
        times.push_back(time);
    }

    double medianTime = median(times);

    std::cout << "Median " << medianTime << " us" << " over " << num_runs << " runs" << std::endl;
}