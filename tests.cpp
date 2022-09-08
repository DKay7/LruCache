#include <string>
#include <fstream>
#include <iostream>
#include "tests.h"
#include "lru.h"

LruCacheTests::LruCacheTests(const std::string filename): test_file(filename), test_results() {}

int LruCacheTests::ProcessOneTest() {
    int cache_size = 0, num_data = 0;
    test_file >> num_data >> cache_size;

    LruCache<int, int> lru {cache_size};

    int cur_page = 0, cache_hits = 0;
    while ((--num_data >= 0) && (test_file.peek() != '\n') && (test_file >> cur_page))
        cache_hits += lru.lookup_insert(cur_page, cur_page);

    return cache_hits;
}

LruCacheTests::it_pair LruCacheTests::ProcessTests() {
    while (!test_file.eof()) {
        int cache_hits = ProcessOneTest();
        test_results.push_back(cache_hits);
    }

    return GetResultVector();
}

LruCacheTests::it_pair LruCacheTests::GetResultVector() const {
    return std::pair<cit, cit> {test_results.cbegin(), test_results.cend()};
}