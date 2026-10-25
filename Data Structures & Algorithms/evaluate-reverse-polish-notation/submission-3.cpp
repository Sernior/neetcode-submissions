class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        auto isOperator = [](string s){
            return s == "+" || s == "-" || s == "*" || s == "/";
        };
        auto solve = [](int b, int a, char op){
            if (op == '/')return a / b;
            if (op == '*')return a * b;
            if (op == '-')return a - b;
            if (op == '+')return a + b;
            return 0;
        };
        std::vector<int> operandStack;
        for(string s : tokens){
            if(isOperator(s)){
                int a = operandStack.back();
                operandStack.pop_back();
                int b = operandStack.back();
                operandStack.pop_back();
                operandStack.push_back(solve(a, b, s[0]));
            }
            else operandStack.push_back(std::stoi(s));
        }
        return operandStack.back();
    }
};
