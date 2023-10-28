#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

double median(std::vector<int>& vec);

void benchmark(void (*func)(), int num_runs);