class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int size = nums.size();
        int temp = 1;
        int prev = -1;

        int res = 0;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) {
                temp++;
                if (!(temp & 1)) {
                    res = max(res, temp/2);
                }
                res = max(res, min(prev, temp));
            } else {
                prev = temp;
                temp = 1;
                res = max(res, min(prev, temp));
            }
        }

        return res;
    }
};
