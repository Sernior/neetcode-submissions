class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int validSize = numbers.size()-1;
        int begin = 0;
        while(true){
            auto sum = numbers[begin] + numbers[validSize];
            if (sum == target)break;
            if (sum > target)--validSize;
            if (sum < target)++begin;
        }
        return {++begin,++validSize};
    }
};
