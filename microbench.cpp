#include <benchmark/benchmark.h>

#include "absl/strings/str_cat.h"
#include "strcat.h"

static void BM_Baseline_ShortStringLiteral_2(benchmark::State& state) {
    for(auto _ : state) {
        std::string s;
        s.reserve(6); 
        s.append("foo").append("bar");
    }
} BENCHMARK(BM_Baseline_ShortStringLiteral_2);

static void BM_Minimal_ShortStringLiteral_2(benchmark::State& state) {
    for(auto _ : state)
        std::string s = minimal::strcat("foo", "bar");
} BENCHMARK(BM_Minimal_ShortStringLiteral_2);

static void BM_Abseil_ShortStringLiteral_2(benchmark::State& state) {
    for(auto _ : state)
        std::string s = absl::StrCat("foo", "bar");
} BENCHMARK(BM_Abseil_ShortStringLiteral_2);




static void BM_Baseline_ShortStringLiteral_10(benchmark::State& state) {
    for(auto _ : state) {
        std::string s;
        s.reserve(30);
        s.append("foo").append("bar").append("bat").append("hat")
            .append("cat").append("dog").append("bog").append("cog")
            .append("log").append("sob");
    }
      
} BENCHMARK(BM_Baseline_ShortStringLiteral_10);

static void BM_Minimal_ShortStringLiteral_10(benchmark::State& state) {
    for(auto _ : state)
        std::string s = minimal::strcat("foo", "bar", "bat", "hat", "cat",
            "dog", "bog", "cog", "log", "sob");
} BENCHMARK(BM_Minimal_ShortStringLiteral_10);

static void BM_Abseil_ShortStringLiteral_10(benchmark::State& state) {
    for(auto _ : state)
        std::string s = absl::StrCat("foo", "bar", "bat", "hat", "cat",
            "dog", "bog", "cog", "log", "sob");
} BENCHMARK(BM_Abseil_ShortStringLiteral_10);




static void BM_Baseline_LongStringLiteral_2(benchmark::State& state) {
    for(auto _ : state) {
        std::string s;
        s.reserve(60); 
        s.append("012345678901234567890123456789")
            .append("123456789012345678901234567890");
    }
} BENCHMARK(BM_Baseline_LongStringLiteral_2);

static void BM_Minimal_LongStringLiteral_2(benchmark::State& state) {
    for(auto _ : state)
        std::string s = minimal::strcat(
            "012345678901234567890123456789", "123456789012345678901234567890");
} BENCHMARK(BM_Minimal_LongStringLiteral_2);

static void BM_Abseil_LongStringLiteral_2(benchmark::State& state) {
    for(auto _ : state)
        std::string s = absl::StrCat(
            "012345678901234567890123456789", "123456789012345678901234567890");
} BENCHMARK(BM_Abseil_LongStringLiteral_2);




static void BM_Baseline_LongStringLiteral_10(benchmark::State& state) {
    for(auto _ : state) {
        std::string s;
        s.reserve(300); 
        s.append("012345678901234567890123456789")
            .append("123456789012345678901234567890").append("234567890123456789012345678901")
            .append("345678901234567890123456789012").append("456789012345678901234567890123")
            .append("567890123456789012345678901234").append("678901234567890123456789012345")
            .append("789012345678901234567890123456").append("890123456789012345678901234567")
            .append("901234567890123456789012345678");
    }
} BENCHMARK(BM_Baseline_LongStringLiteral_10);

static void BM_Minimal_LongStringLiteral_10(benchmark::State& state) {
    for(auto _ : state)
        std::string s = minimal::strcat(
            "012345678901234567890123456789", "123456789012345678901234567890",
            "234567890123456789012345678901", "345678901234567890123456789012",
            "456789012345678901234567890123", "567890123456789012345678901234",
            "678901234567890123456789012345", "789012345678901234567890123456",
            "890123456789012345678901234567", "901234567890123456789012345678");
} BENCHMARK(BM_Minimal_LongStringLiteral_10);

static void BM_Abseil_LongStringLiteral_10(benchmark::State& state) {
    for(auto _ : state)
        std::string s = absl::StrCat(
            "012345678901234567890123456789", "123456789012345678901234567890",
            "234567890123456789012345678901", "345678901234567890123456789012",
            "456789012345678901234567890123", "567890123456789012345678901234",
            "678901234567890123456789012345", "789012345678901234567890123456",
            "890123456789012345678901234567", "901234567890123456789012345678");
} BENCHMARK(BM_Abseil_LongStringLiteral_10);




static void BM_Baseline_ShortStrPtr_2(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "foo";
    const char * const s1 = "bar";
    for(auto _ : state) {
        std::string s;
        s.reserve(std::strlen(s0) + std::strlen(s1));
        s.append(s0).append(s1);
    }
} BENCHMARK(BM_Baseline_ShortStrPtr_2);

static void BM_Minimal_ShortStrPtr_2(benchmark::State& state) {
    const char * const s0 = "foo";
    const char * const s1 = "bar";
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1);
} BENCHMARK(BM_Minimal_ShortStrPtr_2);

static void BM_Abseil_ShortStrPtr_2(benchmark::State& state) {
    const char * const s0 = "foo";
    const char * const s1 = "bar";
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1);
} BENCHMARK(BM_Abseil_ShortStrPtr_2);




static void BM_Baseline_ShortStrPtr_10(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "foo";
    const char * const s1 = "bar";
    const char * const s2 = "bat";
    const char * const s3 = "hat";
    const char * const s4 = "cat";
    const char * const s5 = "dog";
    const char * const s6 = "bog";
    const char * const s7 = "cog";
    const char * const s8 = "log";
    const char * const s9 = "sob";
    for(auto _ : state) {
        std::string s;
        using std::strlen;
        
        s.reserve(strlen(s0) + strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) +
            strlen(s5) + strlen(s6) + strlen(s7) + strlen(s8) + strlen(s9));
        
        s.append(s0).append(s1).append(s2).append(s3).append(s4).append(s5)
            .append(s6).append(s7).append(s8).append(s9);
    }
} BENCHMARK(BM_Baseline_ShortStrPtr_10);

static void BM_Minimal_ShortStrPtr_10(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "foo";
    const char * const s1 = "bar";
    const char * const s2 = "bat";
    const char * const s3 = "hat";
    const char * const s4 = "cat";
    const char * const s5 = "dog";
    const char * const s6 = "bog";
    const char * const s7 = "cog";
    const char * const s8 = "log";
    const char * const s9 = "sob";
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Minimal_ShortStrPtr_10);

static void BM_Abseil_ShortStrPtr_10(benchmark::State& state) {
    const char * const s0 = "foo";
    const char * const s1 = "bar";
    const char * const s2 = "bat";
    const char * const s3 = "hat";
    const char * const s4 = "cat";
    const char * const s5 = "dog";
    const char * const s6 = "bog";
    const char * const s7 = "cog";
    const char * const s8 = "log";
    const char * const s9 = "sob";
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Abseil_ShortStrPtr_10);




static void BM_Baseline_LongStrPtr_2(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "012345678901234567890123456789";
    const char * const s1 = "123456789012345678901234567890";
    for(auto _ : state) {
        std::string s;
        s.reserve(std::strlen(s0) + std::strlen(s1));
        s.append(s0).append(s1);
    }
} BENCHMARK(BM_Baseline_LongStrPtr_2);

static void BM_Minimal_LongStrPtr_2(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "012345678901234567890123456789";
    const char * const s1 = "123456789012345678901234567890";
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1);
} BENCHMARK(BM_Minimal_LongStrPtr_2);

static void BM_Abseil_LongStrPtr_2(benchmark::State& state) {
    const char * const s0 = "012345678901234567890123456789";
    const char * const s1 = "123456789012345678901234567890";
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1);
} BENCHMARK(BM_Abseil_LongStrPtr_2);




static void BM_Baseline_LongStrPtr_10(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "012345678901234567890123456789";
    const char * const s1 = "123456789012345678901234567890";
    const char * const s2 = "234567890123456789012345678901";
    const char * const s3 = "345678901234567890123456789012";
    const char * const s4 = "456789012345678901234567890123";
    const char * const s5 = "567890123456789012345678901234";
    const char * const s6 = "678901234567890123456789012345";
    const char * const s7 = "789012345678901234567890123456";
    const char * const s8 = "890123456789012345678901234567";
    const char * const s9 = "901234567890123456789012345678";
    for(auto _ : state) {
        std::string s;
        using std::strlen;
        
        s.reserve(strlen(s0) + strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) +
            strlen(s5) + strlen(s6) + strlen(s7) + strlen(s8) + strlen(s9));
        
        s.append(s0).append(s1).append(s2).append(s3).append(s4).append(s5)
            .append(s6).append(s7).append(s8).append(s9);
    }
} BENCHMARK(BM_Baseline_LongStrPtr_10);

static void BM_Minimal_LongStrPtr_10(benchmark::State& state) {
    // Pretend we don't know the length of the pointed-to strings
    const char * const s0 = "012345678901234567890123456789";
    const char * const s1 = "123456789012345678901234567890";
    const char * const s2 = "234567890123456789012345678901";
    const char * const s3 = "345678901234567890123456789012";
    const char * const s4 = "456789012345678901234567890123";
    const char * const s5 = "567890123456789012345678901234";
    const char * const s6 = "678901234567890123456789012345";
    const char * const s7 = "789012345678901234567890123456";
    const char * const s8 = "890123456789012345678901234567";
    const char * const s9 = "901234567890123456789012345678";
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Minimal_LongStrPtr_10);

static void BM_Abseil_LongStrPtr_10(benchmark::State& state) {
    const char * const s0 = "012345678901234567890123456789";
    const char * const s1 = "123456789012345678901234567890";
    const char * const s2 = "234567890123456789012345678901";
    const char * const s3 = "345678901234567890123456789012";
    const char * const s4 = "456789012345678901234567890123";
    const char * const s5 = "567890123456789012345678901234";
    const char * const s6 = "678901234567890123456789012345";
    const char * const s7 = "789012345678901234567890123456";
    const char * const s8 = "890123456789012345678901234567";
    const char * const s9 = "901234567890123456789012345678";
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Abseil_LongStrPtr_10);




static void BM_Baseline_ShortSTLStr_2(benchmark::State& state) {
    const std::string s0{"foo"};
    const std::string s1{"bar"};
    for(auto _ : state) {
        std::string s;
        s.reserve(s0.length() + s1.length());
        s.append(s0).append(s1);
    }
} BENCHMARK(BM_Baseline_ShortSTLStr_2);

static void BM_Minimal_ShortSTLStr_2(benchmark::State& state) {
    const std::string s0{"foo"};
    const std::string s1{"bar"};
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1);
} BENCHMARK(BM_Minimal_ShortSTLStr_2);

static void BM_Abseil_ShortSTLStr_2(benchmark::State& state) {
    const std::string s0{"foo"};
    const std::string s1{"bar"};
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1);
} BENCHMARK(BM_Abseil_ShortSTLStr_2);




static void BM_Baseline_ShortSTLStr_10(benchmark::State& state) {
    const std::string s0{"foo"};
    const std::string s1{"bar"};
    const std::string s2{"bat"};
    const std::string s3{"hat"};
    const std::string s4{"cat"};
    const std::string s5{"dog"};
    const std::string s6{"bog"};
    const std::string s7{"cog"};
    const std::string s8{"log"};
    const std::string s9{"sob"};
    for(auto _ : state) {
        std::string s;
        s.reserve(s0.length() + s1.length() + s2.length() + s3.length()
            + s4.length() + s5.length() + s6.length() + s8.length()
            + s9.length());
        
        s.append(s0).append(s1).append(s2).append(s3).append(s4).append(s5)
            .append(s6).append(s7).append(s8).append(s9);
    }
} BENCHMARK(BM_Baseline_ShortSTLStr_10);

static void BM_Minimal_ShortSTLStr_10(benchmark::State& state) {
    const std::string s0{"foo"};
    const std::string s1{"bar"};
    const std::string s2{"bat"};
    const std::string s3{"hat"};
    const std::string s4{"cat"};
    const std::string s5{"dog"};
    const std::string s6{"bog"};
    const std::string s7{"cog"};
    const std::string s8{"log"};
    const std::string s9{"sob"};
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Minimal_ShortSTLStr_10);

static void BM_Abseil_ShortSTLStr_10(benchmark::State& state) {
    const std::string s0{"foo"};
    const std::string s1{"bar"};
    const std::string s2{"bat"};
    const std::string s3{"hat"};
    const std::string s4{"cat"};
    const std::string s5{"dog"};
    const std::string s6{"bog"};
    const std::string s7{"cog"};
    const std::string s8{"log"};
    const std::string s9{"sob"};
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Abseil_ShortSTLStr_10);




static void BM_Baseline_LongSTLStr_2(benchmark::State& state) {
    const std::string s0{"012345678901234567890123456789"};
    const std::string s1{"123456789012345678901234567890"};
    for(auto _ : state) {
        std::string s;
        s.reserve(s0.length() + s1.length());
        s.append(s0).append(s1);
    }
} BENCHMARK(BM_Baseline_LongSTLStr_2);

static void BM_Minimal_LongSTLStr_2(benchmark::State& state) {
    const std::string s0{"012345678901234567890123456789"};
    const std::string s1{"123456789012345678901234567890"};
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1);
} BENCHMARK(BM_Minimal_LongSTLStr_2);

static void BM_Abseil_LongSTLStr_2(benchmark::State& state) {
    const std::string s0{"012345678901234567890123456789"};
    const std::string s1{"123456789012345678901234567890"};
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1);
} BENCHMARK(BM_Abseil_LongSTLStr_2);




static void BM_Baseline_LongSTLStr_10(benchmark::State& state) {
    const std::string s0{"012345678901234567890123456789"};
    const std::string s1{"123456789012345678901234567890"};
    const std::string s2{"234567890123456789012345678901"};
    const std::string s3{"345678901234567890123456789012"};
    const std::string s4{"456789012345678901234567890123"};
    const std::string s5{"567890123456789012345678901234"};
    const std::string s6{"678901234567890123456789012345"};
    const std::string s7{"789012345678901234567890123456"};
    const std::string s8{"890123456789012345678901234567"};
    const std::string s9{"901234567890123456789012345678"};
    for(auto _ : state) {
        std::string s;
        s.reserve(s0.length() + s1.length() + s2.length() + s3.length()
            + s4.length() + s5.length() + s6.length() + s8.length()
            + s9.length());
        
        s.append(s0).append(s1).append(s2).append(s3).append(s4).append(s5)
            .append(s6).append(s7).append(s8).append(s9);
    }
} BENCHMARK(BM_Baseline_LongSTLStr_10);

static void BM_Minimal_LongSTLStr_10(benchmark::State& state) {
    const std::string s0{"012345678901234567890123456789"};
    const std::string s1{"123456789012345678901234567890"};
    const std::string s2{"234567890123456789012345678901"};
    const std::string s3{"345678901234567890123456789012"};
    const std::string s4{"456789012345678901234567890123"};
    const std::string s5{"567890123456789012345678901234"};
    const std::string s6{"678901234567890123456789012345"};
    const std::string s7{"789012345678901234567890123456"};
    const std::string s8{"890123456789012345678901234567"};
    const std::string s9{"901234567890123456789012345678"};
    for(auto _ : state)
        std::string s = minimal::strcat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Minimal_LongSTLStr_10);

static void BM_Abseil_LongSTLStr_10(benchmark::State& state) {
    const std::string s0{"012345678901234567890123456789"};
    const std::string s1{"123456789012345678901234567890"};
    const std::string s2{"234567890123456789012345678901"};
    const std::string s3{"345678901234567890123456789012"};
    const std::string s4{"456789012345678901234567890123"};
    const std::string s5{"567890123456789012345678901234"};
    const std::string s6{"678901234567890123456789012345"};
    const std::string s7{"789012345678901234567890123456"};
    const std::string s8{"890123456789012345678901234567"};
    const std::string s9{"901234567890123456789012345678"};
    for(auto _ : state)
        std::string s = absl::StrCat(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
} BENCHMARK(BM_Abseil_LongSTLStr_10);

BENCHMARK_MAIN();
