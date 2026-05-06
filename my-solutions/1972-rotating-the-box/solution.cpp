class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for (int i = 0; i < n; i++) {
            int idx_plus = 0;
            for (int j = m-1; j >= 0; j--) {
                if (boxGrid[i][j] == '.') {
                    idx_plus++;
                } else if (boxGrid[i][j] == '*') {
                    idx_plus = 0;
                } else {
                    if (idx_plus != 0) {
                        boxGrid[i][j + idx_plus] = boxGrid[i][j];
                        boxGrid[i][j] = '.';
                    }
                }
            }
        }

        vector<vector<char>>res(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = boxGrid[n - 1 - j][i];
            }
        }

        return res;
    }
};
