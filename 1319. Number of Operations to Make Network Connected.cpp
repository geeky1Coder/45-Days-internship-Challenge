class Solution {
public:
    void dfs_util(vector<int> adj[], int index, bool visited[]) {
    visited[index] = true;
    for (auto it = adj[index].begin(); it != adj[index].end(); ++it) {
        if (visited[*it] == false) {
            dfs_util(adj, *it, visited);
        }
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
        return -1;
    }
    bool visited[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    vector<int> adj[n];
    int pairs = 0;
    for (auto el : connections) {
        adj[el[0]].push_back(el[1]);
        adj[el[1]].push_back(el[0]);
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i] == false) {
            ++pairs;
            dfs_util(adj, i, visited);
        }
    }
    return pairs-1;
}
};