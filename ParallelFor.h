#pragma once
#include <functional>

void ParallelFor(size_t count, std::function<void(size_t)> func, size_t min_chunk=0);


void ParallelFor(size_t count,
                 std::function<void(size_t)> prep_func,
                 std::function<void(size_t, size_t)> func,
                 std::function<void(size_t)> accum_func, size_t min_chunk = 0);
