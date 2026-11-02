/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> oldToNew;
        auto oldNode = head;
        auto const headCopy = new Node(oldNode->val);
        auto newNode = headCopy;
        oldToNew[oldNode] = newNode;
        while (oldNode)
        {
            if (oldNode->next){
                if (!oldToNew.contains(oldNode->next)){
                    auto newNodeNext = new Node(oldNode->next->val);
                    newNode->next = newNodeNext;
                    oldToNew[oldNode->next] = newNodeNext;
                }
                else{
                    newNode->next = oldToNew[oldNode->next];
                }
            }
            if (oldNode->random){
                if (!oldToNew.contains(oldNode->random)){
                    auto newNodeRand = new Node(oldNode->random->val);
                    newNode->random = newNodeRand;
                    oldToNew[oldNode->random] = newNodeRand;
                }
                else{
                    newNode->random = oldToNew[oldNode->random];
                }
            }
            newNode = oldToNew[oldNode->next];
            oldNode = oldNode->next;
        }
        return headCopy;
    }
};
