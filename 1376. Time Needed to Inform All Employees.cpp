class Solution {
public:
    int dfs(vector<vector<int>> &adj, int idx, vector<int>& informTime) {
        int sm = 0;

        for (auto it = adj[idx].begin(); it != adj[idx].end(); ++it) {
            sm = max(sm,dfs(adj, (*it), informTime));
        }

        return sm + informTime[idx];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        
        return dfs(adj, headID, informTime);
    }
};