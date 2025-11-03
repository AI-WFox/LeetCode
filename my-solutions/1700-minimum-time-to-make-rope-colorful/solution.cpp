class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int si = neededTime.size();
        int res = 0;

        for (int i = 1; i < si; i++) {
            char pre_color = colors[i-1];
            char cur_color = colors[i];

            if (pre_color == cur_color) {
                if (neededTime[i-1] > neededTime[i]) {
                    swap(neededTime[i-1], neededTime[i]);
                    swap(colors[i-1], colors[i]);
                } 
                res += neededTime[i-1];
            }
        }

        return res;
    }
};
