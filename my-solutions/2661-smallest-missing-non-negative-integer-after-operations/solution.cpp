class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0) {
                double temp = 1.0 * (-nums[i]) / value;
                if (temp != int (temp)) {
                    temp+=1;
                }
                int x = int (temp);
                nums[i]+=(value*x);
            } 
            else {
                int x = 1.0 * nums[i] / value;
                nums[i]-=(value*x);
            }
        }

        sort(nums.begin(), nums.end());

        int prev = nums[0];
        int multi = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] == prev) {
                nums[i] += multi * value;
                multi++;
            }
            else {
                prev = nums[i];
                multi = 1;
            }
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return size;
    }
};
