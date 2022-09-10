#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

class LruCacheTests
{
    private:
        using const_it = std::vector<int>::const_iterator;
        using it_pair = std::pair<const_it, const_it>;
        
        std::filesystem::directory_iterator test_files_dir_it;
        std::ofstream output_file;
        std::vector<int> test_results;
        int ProcessOneTest(std::string filename);
        
    public:
        LruCacheTests(const std::string tests_dir, const std::string output_file_name);
        it_pair ProcessTests();
        it_pair GetResultVector() const;
        void WriteTestResultToFile();
};