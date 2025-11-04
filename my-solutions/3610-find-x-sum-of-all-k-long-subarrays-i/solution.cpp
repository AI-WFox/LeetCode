class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int si = nums.size();

        vector<int>res;
        for (int i = 0; i < si - k + 1; i++) {
            map<int, int>mp;
            for (int j = 0; j < k; j++) {
                mp[nums[i+j]]++;
            }
            vector<pair<int, int>>sortVec;
            for (auto &e: mp) {
                sortVec.push_back({e.second, e.first});
            }
            sort(sortVec.begin(), sortVec.end());
            reverse(sortVec.begin(), sortVec.end());

            int temp = 0;
            int siSV = sortVec.size();
            for (int j = 0; j < min(x, siSV); j++) {
                temp += sortVec[j].second * sortVec[j].first;
            }
            res.push_back(temp);
        }

        return res;
    }
};
