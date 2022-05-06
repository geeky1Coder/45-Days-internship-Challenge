class Solution {
public:
      bool dfs(vector<vector<int>>& graph, int idx, vector<int> &color) {
        color[idx] = 1;
        for (auto it = graph[idx].begin(); it != graph[idx].end(); ++it) {
            if (color[(*it)] == 1) {
                return true;
            }
            if (color[(*it)] == 0 && dfs(graph, (*it), color)) {
                return true;
            }
        }
        color[idx] = 2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<bool> ans(n,false);
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, i, color) && color[i] != 2) {
                ans[i]=true;
            }
        }
        
        vector<int> fans;
        for(int i=0;i<n;++i){
            if(ans[i]==false){
                fans.push_back(i);
            }
        }
        return fans;
    }
};