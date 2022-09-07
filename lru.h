#include <unordered_map>
#include <iostream>
#include <list>

template <typename I, typename P>
class LruCache
{   
    private:
        int cache_size;
        std::list<P> page_list;
        using it = typename std::list<P>::iterator;
        std::unordered_map<I, it> hashtable;
        bool delete_last_element_if_needed();

    public:
        LruCache(int size): cache_size(size) {}
        bool lookup_insert(I page_id, P page);
        void print_cache_data();
};

template <typename I, typename P>
bool LruCache<I, P>::delete_last_element_if_needed() {
    if (page_list.size() > cache_size) {
        auto least_used = hashtable.find(page_list.back());
        hashtable.erase(least_used->first);
        page_list.pop_back();

        return true;
    }

    return false;
}


template <typename I, typename P>
bool LruCache<I, P>::lookup_insert(I page_id, P page) {
    
    // delete page if list size is more than cache size    
    delete_last_element_if_needed();

    auto cached_page = hashtable.find(page_id);
    
    if (cached_page == hashtable.end()) {
        // slow_get_page()
        
        // insert page to list and to hashtable
        page_list.push_front (page);
        hashtable.insert ({page_id, page_list.begin()});
        return false;
    }

    //move page to list head
    page_list.splice(page_list.begin(), page_list, cached_page->second);
        
    return true;
}


template <typename I, typename P>
void LruCache<I, P>::print_cache_data() {

    for (auto &it : page_list) {
        std::cout << it << std::endl;
    }
}
