#include <string>
#include <vector>
#include <fstream>

class LruCacheTests
{
    private:
        using cit = std::vector<int>::const_iterator;
        using it_pair = std::pair<cit, cit>;

        std::ifstream test_file;
        std::vector<int> test_results;
        int ProcessOneTest();
        
    public:
        LruCacheTests(std::string filename);
        it_pair ProcessTests();
        it_pair GetResultVector() const;
};