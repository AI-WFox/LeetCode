class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int>mp;
        int si = nums.size();
        vector<int>res;

        for (int i = 0; i < si; i++) {
            mp[nums[i]]++;
        }

        for (auto &e: mp) {
            if (e.second >= 2) res.push_back(e.first);
        }
        
        return res;
    }
};
