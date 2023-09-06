class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>index;
    vector<int>res;
      for (int i = 0; i<nums.size(); i++){
        if (index.count(target-nums[i])) {
            res.push_back (i);
            res.push_back (index[target - nums[i]]);
        }
        index[nums[i]]=i;
        }
       return res;

    }
    };
