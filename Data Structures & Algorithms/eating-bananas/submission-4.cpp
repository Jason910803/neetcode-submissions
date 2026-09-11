class Solution {
    bool canFinish(const vector<int>& piles, int h, int val) {
        int count = 0;

        for (int pile : piles) {
            // count += (pile + val - 1) / val;
            count += pile / val + (pile % val != 0);
            if (count > h) return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        int left = 1, right = maxPile + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};
