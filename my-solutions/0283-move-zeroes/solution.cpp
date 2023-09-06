class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = 0;
        int b = nums.size();
        int c = 0;
        while (a<b) {
            if (nums[a]==0) {
                nums.erase(nums.begin()+a);
                nums.push_back(c);
                b--;
            }
            else {
                a++;
            }
        }
    }
};
