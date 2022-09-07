#include <iostream>
#include "lru.h"

int main() {
    int n = 0;
    std::cin >> n;  

    LruCache<int> lru;

    while (n--) {
        int page = 0;
        std::cin >> page;
        
        lru.lookup_insert(page, page);
    }
    
    lru.print_cache_data();

    return 0;
}