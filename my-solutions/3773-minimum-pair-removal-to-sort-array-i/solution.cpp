class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;

        while (true) {
            int si = nums.size();
            bool flag = 1;

            for (int i = 1; i < si; i++) {
                if (nums[i-1] > nums[i]) {
                    flag = 0; break;
                }
            }

            if (flag) break;

            int id_left, id_right;
            int min_val = 1000*50+7;

            for (int i = 1; i < si; i++) {
                int temp = nums[i-1] + nums[i];
                if (temp < min_val) {
                    min_val = temp;
                    id_left = i-1;
                    id_right = i;
                }
            }

            nums[id_left] += nums[id_right];
            nums.erase(nums.begin() + id_right);
            res++;
        }

        return res;
    }
};
