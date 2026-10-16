class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int maxProfit = 0;
        while (j < prices.size()){
            int profit = prices[j] - prices[i];
            if (profit > 0){
                maxProfit = max(maxProfit, profit);
                ++j;
            }
            else{
                i = j;
                ++j;
            }
        }
        return maxProfit;
    }
};
