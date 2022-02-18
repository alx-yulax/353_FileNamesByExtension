#include <iostream>
#include <filesystem>
#include <vector>

auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, std::filesystem::path extension) {
    std::vector<std::filesystem::path> names;
    for (auto &p: std::filesystem::recursive_directory_iterator(path)) {
        if (!p.path().extension().compare(extension))
            names.push_back(p.path().filename());
    }
    return names;
};

int main() {

    auto names = recursiveGetFileNamesByExtension(std::filesystem::path("D:\\Bases"), std::filesystem::path(".1CD"));
    for (auto &name: names) {
        std::cout << name << std::endl;
    }
    return 0;
}
