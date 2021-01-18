//
// Created by demonic on 10/20/20.
//

#ifndef DEMONIC_STRINGS_H
#define DEMONIC_STRINGS_H

#include <iostream>
#include <vector>


namespace demonic {
    enum Styles {regular, bold, underline, italic};
    enum Colors {black, red, green, yellow, blue, purple, grey};

    bool string_in_string(const std::string& str, const std::string& full_str);

    std::vector<std::string> string_pong(const std::string &str);

    std::string string_space(const std::string &str, size_t spaces);

    std::string string_color(const std::string &to_color, Colors color = Colors::black, Styles style = Styles::regular);

    std::string string_highlight(std::string str, const std::string& to_highlight, Colors color, Styles style);

    std::string string_lower(const std::string &str);

    std::string string_upper(const std::string &str);

    std::string string_from_bash(std::string command);

    bool string_in_vector(std::string str, std::vector<std::string> vec);
}
#endif //DEMONIC_STRINGS_H
