//Undirected Graph
class Solution {
  public:
    bool isCyclicUtil(vector<int> adj[],int idx,vector<bool> &visited,int parent){
        visited[idx]=true;
        
        for(auto it=adj[idx].begin();it!=adj[idx].end();++it){
            if(!visited[(*it)]){
                if(isCyclicUtil(adj,(*it),visited,idx)){
                    return true;
                }
            }
            else if(parent!=(*it)){
                return true;
            }
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        for(int i=0;i<V;++i){
            vector<bool> visited(V,false);
            if(isCyclicUtil(adj,i,visited,-1)){
                return true;
            }
        }
        
        return false;
    }
};

//Directed Graph

//Using Colors

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detectCycle(vector<int> adj[],int idx,vector<int> &color){
       color[idx]=1;
       
        for(auto it=adj[idx].begin();it!=adj[idx].end();++it){
            if(color[(*it)]==1){
                return true;
            }
            
            if(color[(*it)]==0&&detectCycle(adj,(*it),color)){
                return true;
            }
        }
        
       color[idx]=2;
       return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
       vector<int> color(V,0);
        for(int i=0;i<V;++i){
            if(color[i]==0&&detectCycle(adj,i,color)){
                return true;
            }
        }
        
        return false;
    }
};

//using rec stack

bool isCyclic_util(int s,vector<int> adj[], bool *visited, bool* r_stack) {
	if (visited[s] == false) {
		visited[s] = true;
		r_stack[s] = true;
		auto it = adj[s].begin();
		for (it = it; it != adj[s].end(); ++it) {
			if (visited[*it] == false && isCyclic_util(*it,adj, visited, r_stack)) {
				return true;
			}
			else if (r_stack[*it] == true) {
				return true;
			}
		}
	}
	r_stack[s] = false;
	return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool*visited = new bool[V];
	bool*r_stack = new bool[V];
	for (int i{0}; i < V; ++i) {
		visited[i] = false;
		r_stack[i] = false;
	}
	for (int i{0}; i < V; ++i) {
		if (isCyclic_util(i,adj, visited, r_stack)) {
			return true;
		}
	}
	return false;
}