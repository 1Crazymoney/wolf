//
// Created by demonic on 10/20/20.
//

#include "strings.h"
#include <assert.h>

bool demonic::string_in_string(const std::string& str, const std::string& full_str) {
    if (str.length() <= full_str.length()) {
        for (int i = 0; i < full_str.length(); ++i) {
            if (full_str.substr(i, str.length()) == str && (i + str.length()) <= full_str.length()) {
                return true;
            }
        }
    }
    return false;
}

std::string demonic::string_space(const std::string &str, size_t spaces) {
    std::string result;
    if (spaces >= str.length()) {
        result = str;
        spaces -= str.length();
        for (int i = 0; i < spaces; ++i) {
            result.push_back(' ');
        }
    }
    return result;
}

std::vector<std::string> demonic::string_pong(const std::string &str) {
    std::vector<std::string> vec;
    int full_length = str.length();
    for (int i = 0; i < full_length; i++) {
        size_t sub_length = full_length - i;
        size_t play = full_length - sub_length;
        for (int move_pos = 0; move_pos <= play; move_pos++) {
            std::string sub_str = str.substr(move_pos, sub_length);
            vec.push_back(sub_str);
        }
    }
    return vec;
}


std::string demonic::string_color(const std::string &to_color, Colors color, Styles style) {
    std::string result;
    std::string reset = "\u001b[0m";
    std::string style_str;
    std::string color_str;
    switch (color) {
        case black:
            color_str = "\u001b[30m";
            break;
        case red:
            color_str = "\u001b[31m";
            break;
        case green:
            color_str = "\u001b[32m";
            break;
        case yellow:
            color_str = "\u001b[33m";
            break;
        case blue:
            color_str = "\u001b[34m";
            break;
        case purple:
            color_str = "\u001b[35m";
            break;
        case grey:
            color_str = "\u001b[37m";
            break;
    }
    switch (style){

        case regular:
            style_str = "";
            break;
        case bold:
            style_str = "\u001b[1m";
            break;
        case underline:
            style_str = "\u001B[4m";
            break;
        case italic:
            style_str = "\u001B[3m";
            break;
    }

    result = style_str + color_str + to_color + reset;
    return result;
}

std::string demonic::string_highlight(std::string str, const std::string& to_highlight, Colors color, Styles style) {
    std::string result;
    for (size_t i = 0; i < str.length();) {
        if (str.substr(i, to_highlight.length()) == to_highlight) {
            result.append(string_color(to_highlight, color, style));
            i = i + to_highlight.length();
        } else {
            result.push_back(str[i]);
            i++;
        }
    }
    return result;
}

std::string demonic::string_lower(const std::string &str) {
    std::string result;
    for (char c : str) {
        result.push_back(tolower(c));
    }
    return result;
}

std::string demonic::string_upper(const std::string &str) {
    std::string result;
    for (char c : str) {
        result.push_back(toupper(c));
    }
    return result;
}

std::string demonic::string_from_bash(std::string command) {
    std::string data;
    FILE *stream;
    const int maxBuffer = 256;
    char buffer[maxBuffer];
    command.append(" 2>&1");
    stream = popen(command.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, maxBuffer, stream) != nullptr)
                data.append(buffer);
        pclose(stream);
    }
    return data;
}
bool demonic::string_in_vector(std::string str, std::vector<std::string> vec) {
    for (std::string str2 : vec) {
        if (str == str2) {
            return true;
        }
    }
    return false;
}