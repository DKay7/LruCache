#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "tests.h"
#include "lru.h"

LruCacheTests::LruCacheTests(const std::string tests_dir, const std::string output_filename) : 
    test_files_dir_it(tests_dir), output_file(output_filename), test_results() {}

int LruCacheTests::ProcessOneTest(std::string filename) {

    std::ifstream test_file(filename);
    int cache_size = 0, num_data = 0;
    test_file >> cache_size >> num_data;

    LruCache<int, int> lru {cache_size};

    int cur_page = 0, cache_hits = 0;
    while ((--num_data >= 0) && (test_file.peek() != '\n') && (test_file >> cur_page))
        cache_hits += lru.lookup_insert(cur_page, cur_page);

    return cache_hits;
}

LruCacheTests::it_pair LruCacheTests::ProcessTests() {

    for (const auto &test_file : test_files_dir_it){
        
        #ifdef _DEBUG
        std::cout << test_file.path() << std::endl;
        #endif

        int cache_hits = ProcessOneTest(test_file.path());
        test_results.push_back(cache_hits);
    }

    return GetResultVector();
}

LruCacheTests::it_pair LruCacheTests::GetResultVector() const {
    return std::pair<const_it, const_it> {test_results.cbegin(), test_results.cend()};
}

void LruCacheTests::WriteTestResultToFile() {
    for (auto &it : test_results)
        output_file << it << std::endl;
}
