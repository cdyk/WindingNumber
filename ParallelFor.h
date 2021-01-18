#pragma once
#include <functional>

inline void ParallelFor(size_t count, std::function<void(size_t)> func, size_t min_chunk = 0)
{
  for (size_t i = 0; i < count; i++) {
    func(i);
  }
}

inline void ParallelFor(size_t count,
                        std::function<void(size_t)> prep_func,
                        std::function<void(size_t, size_t)> func,
                        std::function<void(size_t)> accum_func, size_t min_chunk = 0)
{
  size_t n = 32;
  prep_func(n);
  for (size_t i = 0; i < count; i++) {
    func(i, i % n);
  }
  for (size_t i = 0; i < n; i++) {
    accum_func(i);
  }
}
