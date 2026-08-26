class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int result = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else {
                result = max(result, price - minPrice);
            }
        }

        return result;
    }
};
