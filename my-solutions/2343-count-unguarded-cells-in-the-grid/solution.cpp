class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix(m, vector<int>(n, 0));

        int sizeyWall = walls.size();

        for (int i = 0; i < sizeyWall; i++) {
            matrix[walls[i][0]][walls[i][1]] = 2;
        }

        int sizeyGuard = guards.size();

        int moveY[4] = {-1, 0, 1, 0};
        int moveX[4] = {0, 1, 0, -1};

        vector<vector<vector<bool>>>lockMove(m, vector<vector<bool>>(n, vector<bool>(4, 1)));

        for (int i = 0; i < sizeyGuard; i++) {
            int start_y = guards[i][0];
            int start_x = guards[i][1];

            matrix[start_y][start_x] = 2;
            for (int k = 0; k < 4; k++) {
                start_y = guards[i][0];
                start_x = guards[i][1];

                if (lockMove[start_y][start_x][k] == 0) continue;
                while (true) {
                    start_y += moveY[k];
                    start_x += moveX[k];

                    if (start_y < 0 || start_y >= m) break;
                    if (start_x < 0 || start_x >= n) break;
                    if (matrix[start_y][start_x] == 2) break;
            
                    matrix[start_y][start_x] = 1;
                    lockMove[start_y][start_x][k] = 0;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) res++;
            }
        }

        return res;
    }
};
