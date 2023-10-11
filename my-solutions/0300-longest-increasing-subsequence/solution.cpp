class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        
        for (int num : nums) {
            int left = 0, right = lis.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (lis[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (left == lis.size()) {
                lis.push_back(num);
            } else {
                lis[left] = num;
            }
        }
        
        return lis.size();
    }
};

