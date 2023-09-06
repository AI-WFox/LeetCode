class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>index;
        bool res;
        res = false;
            for (int i = 0; i < nums.size(); i++) {
                if (index.count(nums[i])){
                    res = true;
                }
                index[nums[i]]=i;
            }
        return res;
    }
};
