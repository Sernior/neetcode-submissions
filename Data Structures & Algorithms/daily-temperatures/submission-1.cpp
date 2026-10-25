class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> tempStack;
        std::vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; --i){
            while(!tempStack.empty() && temperatures[i] >= temperatures[tempStack.back()])tempStack.pop_back();
            res[i] = tempStack.empty() ? 0 : tempStack.back() - i;
            tempStack.push_back(i);
        }
        return res;
    }
};
