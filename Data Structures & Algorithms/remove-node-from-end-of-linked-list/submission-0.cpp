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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr)return nullptr;
        ListNode* const rev = reverseList(head);
        ListNode* prev = nullptr;
        ListNode* current = rev;
        ListNode* next = current->next;
        for (int i = 1; i < n; ++i){
            prev = current;
            current = next;
            next = next->next;
        }
        if (!prev){// erasing last
            return reverseList(next);
        }
        else if (!next){// erasing first
            prev->next = nullptr;
        }
        else {
            prev->next = next;
        }

        return reverseList(rev);

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
