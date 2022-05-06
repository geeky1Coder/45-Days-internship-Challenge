//Using coloing method
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int> color(n,-1);
        
        for(int i=0;i<n;++i){
            if(color[i]==-1){
                queue<int> pq;
                pq.push(i);
                color[i]=1;
               
                while(!pq.empty()){
                    int x=pq.front();
                    
                    pq.pop();
            
                    for(auto el:graph[x]){
                      
                        if(color[el]==-1){
                            color[el]=(1-color[x]);
                            pq.push(el);
                        }
                        else if(color[el]==color[x]){
                            return false;
                        }
                    }
                }                
            }
        }
        
        return true;
    }
};