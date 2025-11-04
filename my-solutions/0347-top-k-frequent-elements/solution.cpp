class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int si = nums.size();

        vector<int>res;
        map<int, int>mp;
        for (int i = 0; i < si; i++) {
            mp[nums[i]]++;
        }

        vector<pair<int, int>>sortVec;
        for (auto &e: mp) {
            sortVec.push_back({e.second, e.first});
        }
        sort(sortVec.begin(), sortVec.end());
        reverse(sortVec.begin(), sortVec.end());

        for (int i = 0; i < k; i++) {
            res.push_back(sortVec[i].second);
        }

        return res;
    }
};
