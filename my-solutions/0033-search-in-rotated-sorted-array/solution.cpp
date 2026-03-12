class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int pos;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            pos = mid;

            if (nums[mid] > nums[r]) {
                l = mid+1;
            } else if (mid > 0 && nums[mid-1] > nums[mid]) {
                break;
            } else {
                r = mid-1;
            }
        }

        l = pos;
        r = nums.size() - 1 + pos;

        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int idx = mid % (nums.size());
            
            if (nums[idx] > target) {
                r = mid - 1;
            } else if (nums[idx] < target) {
                l = mid + 1;
            } else {
                res = idx;
                break;
            }
        }

        return res;
    }
};
