## Preface

Comparison of vector<MyStruct> (MyStruct just a wrapper for int) vs vector<int> copy

## Results

#### i9-9980HK - GCC toolchain with stdlibc++

| Benchmark                                           | Time      | CPU       | Iterations | Throughput |
|-----------------------------------------------------|-----------|-----------|------------|------------|
| BM_copy_vector_of_structures                        | 558006 ns | 557263 ns | 1145       | 1.75243G/s |
| BM_copy_vector_of_structures_memcpy                 | 581709 ns | 580550 ns | 1280       | 1.68213G/s |
| BM_copy_vector_of_structures_range_reserve          | 989279 ns | 988169 ns | 631        | 1011.97M/s |
| BM_copy_vector_of_structures_std_copy               | 825428 ns | 823923 ns | 863        | 1.18526G/s |
| BM_copy_vector_of_structures_std_copy_back_inserter | 577019 ns | 575875 ns | 1181       | 1.69579G/s |
| BM_copy_vector_of_ints                              | 388065 ns | 387678 ns | 1842       | 2.51901G/s |
| BM_copy_vector_of_ints_memcpy                       | 384529 ns | 384104 ns | 1677       | 2.54244G/s |
| BM_copy_vector_of_ints_range_reserve                | 853172 ns | 851390 ns | 814        | 1.14702G/s |
| BM_copy_vector_of_ints_std_copy                     | 408835 ns | 407615 ns | 1806       | 2.39579G/s |
| BM_copy_vector_of_ints_std_copy_back_inserter       | 805369 ns | 804680 ns | 876        | 1.2136G/s  |



#### i9-9980HK - Clang toolchain with libc++

| Benchmark                                           | Time       | CPU        | Iterations | Thoughput  |
|-----------------------------------------------------|------------|------------|------------|------------|
| BM_copy_vector_of_structures                        | 251962 ns  | 251667 ns  | 2481       | 3.88037G/s |
| BM_copy_vector_of_structures_memcpy                 | 424831 ns  | 424186 ns  | 1628       | 2.30221G/s |
| BM_copy_vector_of_structures_range_reserve          | 1154824 ns | 1153022 ns | 615        | 867.286M/s |
| BM_copy_vector_of_structures_std_copy               | 1199840 ns | 1197704 ns | 635        | 834.931M/s |
| BM_copy_vector_of_structures_std_copy_back_inserter | 435286 ns  | 434430 ns  | 1662       | 2.24792G/s |
| BM_copy_vector_of_ints                              | 254127 ns  | 253718 ns  | 2823       | 3.84901G/s |
