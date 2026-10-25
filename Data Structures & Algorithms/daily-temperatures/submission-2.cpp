class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<std::ptrdiff_t> tempStack;
        std::vector<int> res(temperatures.size());
        for (auto i = std::ssize(temperatures) - 1; i >= 0; --i){
            while(!tempStack.empty() && temperatures[i] >= temperatures[tempStack.back()])tempStack.pop_back();
            res[i] = tempStack.empty() ? 0 : static_cast<int>(tempStack.back() - i);
            tempStack.push_back(i);
        }
        return res;
    }
};