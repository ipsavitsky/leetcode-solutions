/**
 * @file 0071.simplify-path.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/simplify-path/
 * @version 0.1
 * @date 2023-04-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <deque>
#include <sstream>
#include <string>

class Solution {
  public:
    std::string simplifyPath(std::string path) {
        std::istringstream ss(path);
        std::string token;
        std::deque<std::string> tokens;
        while (std::getline(ss, token, '/')) {
            if (token != "" && token != "." && token != "..") {
                tokens.push_back(token);
            } else if (token == ".." && !tokens.empty()) {
                tokens.pop_back();
            }
        }
        std::stringstream out_ss;
        while (!tokens.empty()) {
            out_ss << '/';
            out_ss << tokens.front();
            tokens.pop_front();
        }
        return out_ss.tellp() != 0 ? out_ss.str() : "/";
    }
};