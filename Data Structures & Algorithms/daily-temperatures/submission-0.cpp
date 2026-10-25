class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> tempStack;
        std::vector<int> res;
        res.resize(temperatures.size());
        tempStack.push_back(temperatures.size() - 1);
        for (int i = temperatures.size() - 2; i >= 0; --i){
            while(!tempStack.empty() && temperatures[i] >= temperatures[tempStack.back()]){
                tempStack.pop_back();
            }
            if (tempStack.empty()){
                res[i] = 0;
            }
            else{
                res[i] = tempStack.back() - i;
            }
            tempStack.push_back(i);
        }
        return res;
    }
};
