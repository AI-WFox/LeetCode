#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        int maxProfit = 0; 
        int minPrice = prices[0];

        for (int i = 1; i < n; ++i) {
            int currentProfit = prices[i] - minPrice;

            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }

        return maxProfit;
    }
};

