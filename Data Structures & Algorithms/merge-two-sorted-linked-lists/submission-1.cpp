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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)return list2;
        if (!list2)return list1;

        auto selectSmaller = [](ListNode*& list1, ListNode*& list2){
            ListNode* selected;
            if (list1 && !list2){
                selected = list1;
                list1 = list1->next;
            }
            else if (list2 && !list1){
                selected = list2;
                list2 = list2->next;
            }
            else if (list1->val <= list2->val){
                selected = list1;
                list1 = list1->next;
            }
            else if (list1->val > list2->val){
                selected = list2;
                list2 = list2->next;
            }
            return selected;
        };

        ListNode* const begin = selectSmaller(list1, list2);

        auto prev = begin;

        while(list1 || list2){
            auto selected = selectSmaller(list1, list2);
            prev->next = selected;
            prev = selected;
        }
        return begin;

    }
};
