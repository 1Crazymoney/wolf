//
// Created by demonic on 10/20/20.
//

#include "vectors.h"

std::vector<std::string> demonic::vector_from_string(std::string to_vec, char delimit = ' ') {
    int pos = 0, len = 0;
    std::vector<std::string> vec;
    for (int i = 0; i < to_vec.length(); i++) {
        char c = to_vec[i];
        if (c == delimit) {
            vec.push_back(to_vec.substr(pos, len));
            len = 0;
            pos = i + 1;
        } else if (i == to_vec.length() - 1) {
            int end = to_vec.length() - pos;
            vec.push_back(to_vec.substr(pos, end));
        } else {
            len++;
        }
    }
    return vec;
}

std::vector<std::string> demonic::vector_from_file(std::string file_location) {
    std::fstream file_stream(file_location);
    std::vector<std::string> vec;
    std::string str;
    while (file_stream >> str) {
        std::string result;
        for (char c : str) {
            if (c != '\n')
                result.push_back(c);
        }
        vec.push_back(result);
    }
    return vec;
}

std::vector<std::string> demonic::vector_from_bash(std::string command) {
    std::vector<std::string> data;
    FILE *stream;
    const int maxBuffer = 256;
    char buffer[maxBuffer];
    command.append(" 2>&1");
    stream = popen(command.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, maxBuffer, stream) != nullptr)
                data.emplace_back(buffer);
        pclose(stream);
    }
    return data;
}

