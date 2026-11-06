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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto takeAfter = [](ListNode* from, int k) -> ListNode* {
            if (!from)return nullptr;
            auto next = from;
            while(--k){
                next = next->next;
                if(!next)break;
            }
            return next;
        };

        auto left = head;
        auto right = takeAfter(left, k);
        if(!right)return left;
        ListNode* previousTail = nullptr;
        ListNode* newHeadGlobal = nullptr;
        while(right){
            auto nextOutsideGroup = right->next;
            auto newHead = reverseList(left, right);
            if(!newHeadGlobal)newHeadGlobal = newHead;
            left->next = nextOutsideGroup;
            if(previousTail)previousTail->next = newHead;
            previousTail = left;
            left = nextOutsideGroup;
            right = takeAfter(left, k);
        }

        return newHeadGlobal;

    }

private:
    ListNode* reverseList(ListNode* from, ListNode* to) {
        auto prev = from;
        if(!from)return nullptr;
        if(!to)return from;
        auto next = from->next;
        auto stop = to->next;
        while(next != nullptr && next != stop){
            auto nextNext = next->next;
            next->next = prev;
            prev = next;
            next = nextNext;
        }
        from->next = nullptr;
        return prev;
    }
};
