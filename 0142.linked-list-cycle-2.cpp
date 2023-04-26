/**
 * @file 0142.linked-list-cycle-2.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/linked-list-cycle-ii/
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> elems;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (elems.count(cur) != 0) {
                return cur;
            } else {
                elems.insert(cur);
            }
            cur = cur -> next;
        }
        return nullptr;
    }
};