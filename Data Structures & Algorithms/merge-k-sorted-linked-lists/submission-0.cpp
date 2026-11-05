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
#include <set>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* left, ListNode* right) { return left->val < right->val; };
        std::multiset<ListNode*, decltype(cmp)> m_(cmp);

        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        // we put the first N elements of the lists which are the smallest if they exists
        for (size_t i = 0; i < lists.size(); ++i){
            auto current = lists[i];
            if (!current)continue;
            m_.insert(lists[i]);
            lists[i] = lists[i]->next;
        }

        if(m_.size() == 0)return nullptr;

        auto const head = *m_.begin();
        m_.erase(m_.begin());
        if(head->next)m_.insert(head->next);
        auto prev = head;
        auto current = head;

        while (!m_.empty()){
            current = *m_.begin();
            m_.erase(m_.begin());
            if(current->next)m_.insert(current->next);
            prev->next = current;
            prev = current;
        }

        return head;
    }
};