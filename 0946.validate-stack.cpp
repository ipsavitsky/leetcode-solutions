/**
 * @file 0946.validate-stack.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/validate-stack-sequences/
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stack>
#include <vector>

class Solution {
  public:
    bool validateStackSequences(std::vector<int> &pushed,
                                std::vector<int> &popped) {
        std::vector<int>::const_iterator popped_it = popped.cbegin();
        std::vector<int>::const_iterator pushed_it = pushed.cbegin();
        std::stack<int> pot_stack;

        while (!(pushed_it == pushed.cend())) {
            pot_stack.push(*pushed_it);
            while (!pot_stack.empty() && pot_stack.top() == *popped_it &&
                   popped_it != popped.cend()) {
                pot_stack.pop();
                ++popped_it;
            }

            ++pushed_it;
        }

        return pot_stack.empty();
    }
};
