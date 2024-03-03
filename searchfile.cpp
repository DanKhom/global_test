#include "searchfile.h"

namespace fs = std::filesystem;

bool IsFound = false;

void Processing_Directory(std::string target_filename, fs::path rootPath) {
    try {
        for (const auto &entry : fs::directory_iterator(rootPath)) {
            if (IsFound) return;
            
            if (fs::is_regular_file(entry) && entry.path().filename() == target_filename) {
                IsFound = true;
                std::cout << entry.path() << std::endl;
                return;
            } else if (fs::is_directory(entry)) {
                Processing_Directory(target_filename, entry.path());
            }
        }
    } catch (const std::filesystem::filesystem_error &ex) {}
}
