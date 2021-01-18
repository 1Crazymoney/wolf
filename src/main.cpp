#include <boost/filesystem.hpp>
#include <iostream>
#include "../lib/demonic/demonic.h"

namespace fs = boost::filesystem;

std::vector<std::string> files;

void get_files(fs::path &p) {
    try {
        if (exists(p) && is_directory(p) && !is_symlink(p)) {
            fs::directory_iterator it(p);
            while (it != fs::directory_iterator{}) {
                fs::path current_path(*it);
                if (!is_directory(*it)) {
                    files.push_back(it->path().generic_string());
                } else {
                    get_files(current_path);
                }
                it++;
            }
        }
    }
    catch (...) {
    }
}

double match(const std::string &s, const std::string &other) {
    double result = 0;
    for (const std::string &pong : demonic::string_pong(other)) {
        if (demonic::string_in_string(pong, s))
            result += pong.length() * pong.length();
    }
    return result;
}

int main(int argc, char *argv[]) {

    if (argv[1]) {
        std::string arg = argv[1];
    } else {
        fprintf(stderr, "No argument given");
    }

    fs::path p = "/";
    get_files(p);

    double rate_max = match(argv[1], argv[1]);
    //std::vector<std::string> files = demonic::vector_from_bash("find /");
    std::string file;
    std::string file_path;
    for (std::string s : files) {
        if (s.length() > 3 ) {
            int index;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '/') {
                    index = i;
                }
                file = s.substr(index + 1, s.length() - (index + 2));
                file_path = s;
            }
            double rate_file = match(file, argv[1]);
            double rate_percentage = (rate_file / rate_max) * 100;
            if (rate_percentage > 90)
                std::cout << file_path << std::endl;
        }
    }
    return 0;
}
