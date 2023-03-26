## Preface

Comparison of vector<MyStruct> (MyStruct just a wrapper for int) vs vector<int> copy

## Results

#### i9-9980HK - GCC toolchain with stdlibc++

| Benchmark                                           | Time      | CPU       | Iterations | Throughput     |
|-----------------------------------------------------|-----------|-----------|------------|----------------|
| BM_copy_vector_of_structures                        | 576979 ns | 576024 ns | 942        | **1.69535G/s** |
| BM_copy_vector_of_structures_memcpy                 | 577748 ns | 576573 ns | 975        | 1.69374G/s     |
| BM_copy_vector_of_structures_range_reserve          | 963221 ns | 962010 ns | 715        | 1039.49M/s     |
| BM_copy_vector_of_structures_std_copy               | 567281 ns | 566021 ns | 1171       | 1.72531G/s     |
| BM_copy_vector_of_structures_std_copy_back_inserter | 738655 ns | 737857 ns | 780        | 1.32351G/s     |
| BM_copy_vector_of_ints                              | 366610 ns | 366216 ns | 1873       | **2.66663G/s** |
| BM_copy_vector_of_ints_memcpy                       | 366780 ns | 366437 ns | 1872       | 2.66502G/s     |
| BM_copy_vector_of_ints_range_reserve                | 813321 ns | 812090 ns | 756        | 1.20253G/s     |
| BM_copy_vector_of_ints_std_copy                     | 384894 ns | 384137 ns | 1908       | 2.54223G/s     |
| BM_copy_vector_of_ints_std_copy_back_inserter       | 798550 ns | 797727 ns | 819        | 1.22418G/s     |
                                                                                                               



#### i9-9980HK - Clang toolchain with libc++

| Benchmark                                           | Time       | CPU        | Iterations | Throughput     |
|-----------------------------------------------------|------------|------------|------------|----------------|
 | BM_copy_vector_of_structures                        | 229171 ns  | 228937 ns  | 2894       | **4.26563G/s** |
 | BM_copy_vector_of_structures_memcpy                 | 371435 ns  | 371077 ns  | 1786       | 2.6317G/s      |
 | BM_copy_vector_of_structures_range_reserve          | 1117614 ns | 1115697 ns | 643        | 896.301M/s     |
 | BM_copy_vector_of_structures_std_copy               | 1135783 ns | 1134178 ns | 636        | 881.696M/s     |
 | BM_copy_vector_of_structures_std_copy_back_inserter | 380907 ns  | 380080 ns  | 1874       | 2.56936G/s     |
 | BM_copy_vector_of_ints                              | 218235 ns  | 217993 ns  | 3207       | **4.47979G/s** |
 | BM_copy_vector_of_ints_memcpy                       | 388289 ns  | 387696 ns  | 1864       | 2.51888G/s     |
 | BM_copy_vector_of_ints_range_reserve                | 1123663 ns | 1122090 ns | 551        | 891.194M/s     |
 | BM_copy_vector_of_ints_std_copy                     | 386928 ns  | 386154 ns  | 1906       | 2.52895G/s     |
 | BM_copy_vector_of_ints_std_copy_back_inserter       | 1149359 ns | 1147107 ns | 620        | 871.758M/s     |
