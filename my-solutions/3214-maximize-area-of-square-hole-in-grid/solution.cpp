class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int siH = hBars.size();
        int siV = vBars.size();

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int conH = 1;
        int conV = 1;

        int temp = 1;
        for (int i = 1; i < siH; i++) {
            if (hBars[i-1] + 1 == hBars[i]) {
                temp++;
                conH = max(conH, temp);
            } else {
                temp = 1;
            }
        }

        temp = 1;
        for (int i = 1; i < siV; i++) {
            if (vBars[i-1] + 1 == vBars[i]) {
                temp++;
                conV = max(conV, temp);
            } else {
                temp = 1;
            }
        }

        cout << conH << " " << conV;
        return pow((min(conV, conH) + 1), 2);
    }
};
