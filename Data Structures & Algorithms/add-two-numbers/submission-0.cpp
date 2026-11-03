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
#include <utility>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* const resultHead = new ListNode((l1->val + l2->val) % 10);
        ListNode* resultCur = resultHead;
        int rest{(l1->val + l2->val) / 10};
        while (l1->next || l2->next){
            auto nextl1 = l1->next;
            auto nextl2 = l2->next;
            if (nextl1 && nextl2){
                resultCur->next = new ListNode((nextl1->val + nextl2->val + rest) % 10);
                rest = (nextl1->val + nextl2->val + rest) / 10;
                l1 = nextl1;
                l2 = nextl2;
                resultCur = resultCur->next;
                continue;
            }
            if (nextl1 && !nextl2){
                resultCur->next = new ListNode((nextl1->val + rest) % 10);
                rest = (nextl1->val + rest) / 10;
                l1 = nextl1;
                resultCur = resultCur->next;
                continue;
            }
            if (!nextl1 && nextl2){
                resultCur->next = new ListNode((nextl2->val + rest) % 10);
                rest = (nextl2->val + rest) / 10;;
                l2 = nextl2;
                resultCur = resultCur->next;
                continue;
            }
            std::unreachable();
        }
        if (rest > 0)resultCur->next = new ListNode(rest);
        return resultHead;
    }
};
