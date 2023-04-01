#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        using uint = unsigned int;
        const std::string &first = strs[0];
        for (uint i = 0; i < strs[0].size(); ++i) {
            if (std::any_of(strs.begin(), strs.end(),
                            [&i, &first](const std::string &cur) {
                                return cur[i] != first[i];
                            })) {
                return std::string(first.begin(), std::next(first.begin(), i));
            }
        }
        return first;
    }
};