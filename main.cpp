#include "searchfile.h"

int main() {
    std::string target_filename;
    std::cout << "Enter the target filename: ";
    std::cin >> target_filename;

    Processing_Directory(target_filename, std::filesystem::path("/"));

    return 0;
}