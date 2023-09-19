class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freqMap;
        vector<int> res;
        
        for (int num : nums1) {
            freqMap[num]++;
        }
        
        for (int num : nums2) {
            if (freqMap.find(num) != freqMap.end() && freqMap[num] > 0) {
                res.push_back(num);
                freqMap[num]--;
            }
        }
        
        return res;
    }
};

