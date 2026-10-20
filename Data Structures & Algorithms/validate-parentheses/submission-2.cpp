class Solution {
public:
    bool isValid(string& s) {
        std::stack<char> pStack{};
        for (char c : s){
            if (c == '(' || c == '[' || c == '{')pStack.push(c);
            else if (c == ')' || c == ']' || c == '}'){
                if(pStack.empty())return false;
                char topChar = pStack.top();
                if (topChar == '(' && c == ')'){
                    pStack.pop();
                    continue;
                }
                if (topChar == '[' && c == ']'){
                    pStack.pop();
                    continue;
                }
                if (topChar == '{' && c == '}'){
                    pStack.pop();
                    continue;
                }
                return false;
            }
        }
        return pStack.empty();
    }
};
