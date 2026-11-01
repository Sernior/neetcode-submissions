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
    void reorderList(ListNode* head) {
        if (!head) return;
        if (!head->next) return;
        if (!head->next->next) return;
        auto slow = head;
        auto fast = head->next;
        for(;;){
            if (!fast) break;
            fast = fast->next;
            if (!fast) break;
            slow = slow->next;
            fast = fast->next;
        }
        auto rightHalf = slow->next;
        auto leftHalf = head;
        slow->next = nullptr;
        rightHalf = reverseList(rightHalf);

        while (rightHalf && leftHalf)
        {
            auto leftNext = leftHalf->next;
            leftHalf->next = rightHalf;
            auto rightNext = rightHalf->next;
            rightHalf->next = leftNext;
            leftHalf = leftNext;
            rightHalf = rightNext;
        }
    }
private:
    ListNode* reverseList(ListNode* head) {
        auto prev = head;
        if(!head)return nullptr;
        auto next = head->next;
        head->next = nullptr;
        while(next != nullptr){
            auto nextNext = next->next;
            next->next = prev;
            prev = next;
            next = nextNext;
        }
        return prev;
    }
};
