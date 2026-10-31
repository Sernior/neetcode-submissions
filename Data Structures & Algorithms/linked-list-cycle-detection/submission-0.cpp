/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        if (!head->next) return false;
        auto slow = head;
        auto fast = head -> next;
        while (true){
            if (slow == fast) return true;
            if (fast == nullptr) return false;
            slow = slow->next;
            if (fast->next == nullptr) return false;
            fast = fast->next->next;
        }
    }
};
