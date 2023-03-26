#include <algorithm>
#include <iostream>
#include <random>
#include <cstring>

#include <benchmark/benchmark.h>

constexpr auto N = 1 << 20;

struct MyStruct {
  int x;
};

namespace {
void BM_copy_vector_of_structures(benchmark::State &State) {
  std::vector<MyStruct> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<MyStruct> Other(Data.size());

    for (size_t I = 0; I < Data.size(); ++I) {
      Other[I] = Data[I];
    }

    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_structures_memcpy(benchmark::State &State) {
  std::vector<MyStruct> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<MyStruct> Other(Data.size());
    std::memcpy(Other.data(), Data.data(), Data.size() * sizeof(MyStruct));
    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_structures_range_reserve(benchmark::State &State) {
  std::vector<MyStruct> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<MyStruct> Other;
    Other.reserve(Data.size());
    for (auto x : Data)
      Other.push_back(x);

    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_structures_std_copy_back_inserter(benchmark::State &State) {
  std::vector<MyStruct> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<MyStruct> Other(Data.size());
    std::copy(Data.begin(), Data.end(), Other.begin());
    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_structures_std_copy(benchmark::State &State) {
  std::vector<MyStruct> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<MyStruct> Other;
    Other.reserve(Data.size());
    std::copy(Data.begin(), Data.end(), std::back_inserter(Other));
    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_ints(benchmark::State &State) {
  std::vector<int> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<int> Other(Data.size());

    for (size_t I = 0; I < Data.size(); ++I) {
      Other[I] = Data[I];
    }

    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_ints_memcpy(benchmark::State &State) {
  std::vector<int> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<int> Other(Data.size());
    std::memcpy(Other.data(), Data.data(), Data.size() * sizeof(int));
    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_ints_range_reserve(benchmark::State &State) {
  std::vector<int> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<int> Other;
    Other.reserve(Data.size());
    for (auto x : Data)
      Other.push_back(x);

    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_ints_std_copy_back_inserter(benchmark::State &State) {
  std::vector<int> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<int> Other;
    Other.reserve(Data.size());
    std::copy(Data.begin(), Data.end(), std::back_inserter(Other));
    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}

void BM_copy_vector_of_ints_std_copy(benchmark::State &State) {
  std::vector<int> Data;
  std::mt19937 RandomD(std::random_device{}());
  std::uniform_int_distribution<int> D;
  for (size_t I = 0; I < N; ++I) {
    Data.push_back({D(RandomD)});
  }

  for (auto &&_ : State) {
    std::vector<int> Other(Data.size());
    std::copy(Data.begin(), Data.end(), Other.begin());
    benchmark::DoNotOptimize(Other);
  }
  State.SetBytesProcessed(State.iterations() * Data.size());
}
} // namespace

BENCHMARK(BM_copy_vector_of_structures);
BENCHMARK(BM_copy_vector_of_structures_memcpy);
BENCHMARK(BM_copy_vector_of_structures_range_reserve);
BENCHMARK(BM_copy_vector_of_structures_std_copy);
BENCHMARK(BM_copy_vector_of_structures_std_copy_back_inserter);

BENCHMARK(BM_copy_vector_of_ints);
BENCHMARK(BM_copy_vector_of_ints_memcpy);
BENCHMARK(BM_copy_vector_of_ints_range_reserve);
BENCHMARK(BM_copy_vector_of_ints_std_copy);
BENCHMARK(BM_copy_vector_of_ints_std_copy_back_inserter);

BENCHMARK_MAIN();