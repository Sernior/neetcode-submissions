#include<utility>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        auto isOperator = [](string const& s){
            return s == "+" || s == "-" || s == "*" || s == "/";
        };
        auto solve = [](int const a, int const b, char const op){
            if (op == '/')return a / b;
            if (op == '*')return a * b;
            if (op == '-')return a - b;
            if (op == '+')return a + b;
            std::unreachable();
        };
        std::vector<int> operandStack;
        for(string const& s : tokens){
            if(isOperator(s)){
                int rightOperand = operandStack.back();
                operandStack.pop_back();
                int leftOperand = operandStack.back();
                operandStack.pop_back();
                operandStack.push_back(solve(leftOperand, rightOperand, s[0]));
            }
            else operandStack.push_back(std::stoi(s));
        }
        return operandStack.back();
    }
};
