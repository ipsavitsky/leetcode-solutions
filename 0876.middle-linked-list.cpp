/**
 * @file 0876.middle-linked-list.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/middle-of-the-linked-list/
 * @version 0.1
 * @date 2023-04-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        using uint = unsigned int;
        uint list_size = 0;
        ListNode *counter = head;
        while (counter != nullptr) {
            ++list_size;
            counter = counter->next;
        }
        for (uint i = 0; i < list_size; ++i) {
            head = head->next;
        }
        return head;
    }
};