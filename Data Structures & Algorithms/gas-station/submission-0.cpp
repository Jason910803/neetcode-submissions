class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr = 0;
        int total = 0;
        int index = 0;

        for (int i = 0; i < gas.size(); i++) {
            int net = gas[i] - cost[i];

            total += net;
            curr += net;

            if (curr < 0) {
                index = i + 1;
                curr = 0;
            }
        }

        return total >= 0 ? index : -1;
    }
};