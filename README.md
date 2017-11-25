# strcat
Minimalistic, header-only strcat implementation that's still fast and efficient

The codebase I work on most is limited to C++11 and as much as I'd like to add Abseil as a dependency for newer C++ features, that's not something that's palatable at the moment.

One of the things I see others almost always do inefficiently is string concatenation. Almost always that's for logging, so it's something that appears frequently. This strcat implementation is intended to improve the performance of these string concatenations while avoiding an external dependency.

The performance is comparable to Abseil's StrCat in the included benchmarks:


GCC 7.1;
Ubuntu 16.04;
Linux 4.10;
i7-6500U
```
strcat_benchmark
2017-11-25 12:51:41
Run on (4 X 3100 MHz CPU s)
CPU Caches:
  L1 Data 32K
  L1 Instruction 32K
  L2 Unified 256K
  L3 Unified 4096K
-------------------------------------------------------------------------
Benchmark                                  Time           CPU Iterations
-------------------------------------------------------------------------
BM_Baseline_ShortStringLiteral_2          18 ns         18 ns   38344665
BM_Minimal_ShortStringLiteral_2           19 ns         19 ns   36855559
BM_Abseil_ShortStringLiteral_2            16 ns         16 ns   44297477
BM_Baseline_ShortStringLiteral_10         89 ns         89 ns    7804995
BM_Minimal_ShortStringLiteral_10          88 ns         88 ns    7832701
BM_Abseil_ShortStringLiteral_10           80 ns         80 ns    8664640
BM_Baseline_LongStringLiteral_2           40 ns         40 ns   17473436
BM_Minimal_LongStringLiteral_2            40 ns         40 ns   17540705
BM_Abseil_LongStringLiteral_2             46 ns         46 ns   15492763
BM_Baseline_LongStringLiteral_10         118 ns        118 ns    5811316
BM_Minimal_LongStringLiteral_10          120 ns        120 ns    5812499
BM_Abseil_LongStringLiteral_10           119 ns        119 ns    5900929
BM_Baseline_ShortStrPtr_2                 18 ns         18 ns   39267590
BM_Minimal_ShortStrPtr_2                  18 ns         18 ns   38940780
BM_Abseil_ShortStrPtr_2                   15 ns         15 ns   45716809
BM_Baseline_ShortStrPtr_10                89 ns         89 ns    7897463
BM_Minimal_ShortStrPtr_10                 88 ns         88 ns    7927259
BM_Abseil_ShortStrPtr_10                  80 ns         80 ns    8850553
BM_Baseline_LongStrPtr_2                  40 ns         40 ns   17346132
BM_Minimal_LongStrPtr_2                   40 ns         40 ns   17728763
BM_Abseil_LongStrPtr_2                    45 ns         45 ns   15457360
BM_Baseline_LongStrPtr_10                118 ns        118 ns    5926412
BM_Minimal_LongStrPtr_10                 119 ns        119 ns    5870746
BM_Abseil_LongStrPtr_10                  119 ns        119 ns    5897610
BM_Baseline_ShortSTLStr_2                 18 ns         18 ns   39326866
BM_Minimal_ShortSTLStr_2                  18 ns         18 ns   38624694
BM_Abseil_ShortSTLStr_2                   15 ns         15 ns   45917852
BM_Baseline_ShortSTLStr_10                88 ns         88 ns    7926536
BM_Minimal_ShortSTLStr_10                 90 ns         90 ns    7743429
BM_Abseil_ShortSTLStr_10                  80 ns         80 ns    8832356
BM_Baseline_LongSTLStr_2                  55 ns         55 ns   12513462
BM_Minimal_LongSTLStr_2                   39 ns         39 ns   17713246
BM_Abseil_LongSTLStr_2                    45 ns         45 ns   15454816
BM_Baseline_LongSTLStr_10                178 ns        178 ns    3924503
BM_Minimal_LongSTLStr_10                 127 ns        127 ns    5494250
BM_Abseil_LongSTLStr_10                  118 ns        118 ns    5901232

*** Finished ***
```
