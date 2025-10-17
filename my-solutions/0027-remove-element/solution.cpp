class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>res;
        int cnt = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                cnt++;
                res.push_back(nums[i]);
            }
        }
        nums = res;
        return cnt;
    }
};
