class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>> &vis, queue<pair<int, int>> &pq) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[x][y] == 1) {
            grid[x][y] = 0;
            pq.push({x, y});
        }

        for (int i = 0; i < 4; ++i) {
            int destX = dirX[i] + x;
            int destY = dirY[i] + y;

            if (destX >= 0 &&
                    destX < n &&
                    destY >= 0 &&
                    destY < m &&
                    !vis[destX][destY] &&
                    grid[destX][destY] == 1) {

                dfs(grid, destX, destY, vis, pq);
            }
        }
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>> &pq) {
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int sz = pq.size();
        int ans = 0;

        while (sz != 0) {
            for (int i = 0; i < sz; ++i) {
                int rx = pq.front().first;
                int ry = pq.front().second;


                pq.pop();

                for (int i = 0; i < 4; ++i) {
                    int destX = dirX[i] + rx;
                    int destY = dirY[i] + ry;

                    if (destX >= 0 &&
                            destX < n &&
                            destY >= 0 &&
                            destY < m
                       )
                    {
                        if (grid[destX][destY] == 0 && !vis[destX][destY]) {
                            vis[destX][destY] = true;
                            pq.push({destX, destY});
                        }
                        else if (grid[destX][destY] == 1) {
                            return ans;
                        }
                    }
                }
            }

            ans += 1;
            sz = pq.size();
        }
        return ans;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> pq;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            bool f = false;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    vector<vector<bool>> vis(n, vector<bool> (m, false));
                    dfs(grid, i, j, vis, pq);
                    f = true;
                    break;
                }
            }
            if (f) {
                break;
            }
        }

        return bfs(grid, pq);

    }
};
