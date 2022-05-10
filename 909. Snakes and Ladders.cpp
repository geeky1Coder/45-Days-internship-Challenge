class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int> oneD(n*m);
        int t=0;
        int idx=0;
        int i = n - 1, j = 0,inc=1;
        
        while (idx < n * n) {
            oneD[idx++] = board[i][j];
            if (inc == 1 && j == n - 1) {
                inc = -1;
                i--;
            } else if (inc == -1 && j == 0) {
                inc = 1;
                i--;
            } else {
                j += inc;
            }
        }
        queue<int> pq;
        int start = oneD[0] > -1 ? oneD[0] - 1 : 0;
        pq.push(start);
        int sz=1;
        vector<bool> visited((n*n),false);
        int step=0;
        visited[start]=true;
        
        while(sz!=0){
            for(int i=0;i<sz;++i){
                int x=pq.front();
               
                pq.pop();
               
                if(x==((n*n)-1)){
                   return step; 
                }
                
                for(int next=x+1;next<=min(((n*n)-1),x+6);++next){
                    int dest=oneD[next]>-1?oneD[next]-1:next;
                    if(!visited[dest]){
                        visited[dest]=true;
                        pq.push(dest);                        
                    }
                }
            }
            sz=pq.size();
            step++;
        }
        return -1;
    }
};