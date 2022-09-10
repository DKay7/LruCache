#include <numeric>
#include <iostream>
#include "tests.h"


int main () {
    LruCacheTests tests{"../tests/", "../tests/output.result"};
    
    using cit = std::vector<int>::const_iterator;
    std::pair<cit, cit> result_vec_it = tests.ProcessTests();

    #ifdef _DEBUG
    for (auto it = result_vec_it.first; it != result_vec_it.second; ++it)
        std::cout << *it << std::endl;
    
    int total_hits = std::accumulate(result_vec_it.first, result_vec_it.second, 0);
    std::cout << "Total hits: " << total_hits << std::endl;
    #endif

    tests.WriteTestResultToFile();

    return 0;
}