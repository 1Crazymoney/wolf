//
// Created by demonic on 10/20/20.
//

#ifndef DEMONIC_VECTORS_H
#define DEMONIC_VECTORS_H
#include <iostream>
#include <vector>
#include <fstream>

namespace demonic {

    std::vector<std::string> vector_from_file(std::string file_location);

    std::vector<std::string> vector_from_bash(std::string command);

    std::vector<std::string> vector_from_string(std::string to_vec, char delimit);
}
#endif //DEMONIC_VECTORS_H
