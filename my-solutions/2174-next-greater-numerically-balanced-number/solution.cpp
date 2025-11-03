class Solution {
public:
    int nextBeautifulNumber(int n) {
        int res = n + 1;
        while (true) {
            string number = to_string(res);
            int si = number.size();

            map<char, int>mp;
            for (int i = 0; i < si; i++) {
                mp[number[i]]++;
            }

            bool flag = 1;
            for (auto &e: mp) {
                if ((e.first - '0') != e.second) {
                    flag = 0;
                    break;
                }
            }

            if (flag) break;

            res++;
        }

        return res;
    }
};
