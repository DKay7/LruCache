#include <unordered_map>
#include <iostream>
#include <list>

template <typename P>
class LruCache
{   
    private:   
        std::list <P> page_list;
        // TODO problem is here: how to make it like...
        // std::unordered_map<int, std::list<P>::iterator> hashtable
        std::unordered_map<int, std::list<int>::iterator> hashtable;

    public:
        bool lookup_insert(int page_id, P page);
        void print_cache_data();
};    


template <typename P>
bool LruCache<P>::lookup_insert(int page_id, P page) {
    
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


template <typename P>
void LruCache<P>::print_cache_data() {

    for (auto &it : page_list) {
        std::cout << it << std::endl;
    }
}
