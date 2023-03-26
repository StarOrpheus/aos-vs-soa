## Preface

Comparison of vector<MyStruct> (MyStruct just a wrapper for int) vs vector<int> copy

## Results

#### i9-9980HK - GCC toolchain with stdlibc++

| Benchmark                                  | Time      | CPU       | Iterations | Throughput |
|--------------------------------------------|-----------|-----------|------------|------------|
| BM_copy_vector_of_structures               | 530217 ns | 529458 ns | 1219       | 1.84446G/s |
| BM_copy_vector_of_structures_range_reserve | 835599 ns | 833853 ns | 839        | 1.17114G/s |
| BM_copy_vector_of_structures_std_copy      | 808617 ns | 807561 ns | 818        | 1.20927G/s |
| BM_copy_vector_of_ints                     | 375849 ns | 375408 ns | 1709       | 2.60134G/s |
| BM_copy_vector_of_ints_range_reserve       | 999301 ns | 997473 ns | 691        | 1002.53M/s |
| BM_copy_vector_of_ints_std_copy            | 752010 ns | 751239 ns | 887        | 1.29994G/s |


#### i9-9980HK - Clang toolchain with libc++

| Benchmark                                  | Time       | CPU        | Iterations | Throughput |
|--------------------------------------------|------------|------------|------------|------------|
| BM_copy_vector_of_structures               | 229061 ns  | 228511 ns  | 3068       | 4.27359G/s |
| BM_copy_vector_of_structures_range_reserve | 1135954 ns | 1133798 ns | 627        | 881.992M/s |
| BM_copy_vector_of_structures_std_copy      | 1108562 ns | 1107114 ns | 642        | 903.25M/s  |
| BM_copy_vector_of_ints                     | 219725 ns  | 219468 ns  | 2939       | 4.44969G/s |
| BM_copy_vector_of_ints_range_reserve       | 1140654 ns | 1138533 ns | 619        | 878.323M/s |
| BM_copy_vector_of_ints_std_copy            | 1118975 ns | 1117082 ns | 635        | 895.189M/s |
