class Solution {
public:
     string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.size();
        int i = 0;
        vector<pair<char, int>> vec;

        while (i < n) {
            char c = s[i];
            int j = i;
            int ax = 0;
            while (j < n && s[j] == c) {
                j++;
                ax++;
            }
            ax%=k;
            if(ax>0){
            vec.push_back({c, ax});                
            }
            i = j;
        }
       
        i = 0;
        while (i < vec.size()) {
            if (!st.empty()) {
                auto x = st.top();
                if (x.first == vec[i].first) {
                    st.pop();
                    int ax=(x.second + vec[i].second);
                    ax%=k;
                    if(ax>0){
                        st.push({x.first,ax});              
                    }
                }
                else {
                    st.push(vec[i]);
                }
            }
            else {
                st.push(vec[i]);
            }
        
            i++;
        }
        
        string ans;
        while(!st.empty()){
            auto c=st.top();
            st.pop();
            string add;
            for(int i=0;i<c.second;++i){
                add+=c.first;
            }
            ans=add+ans;
        }
        
        return ans;
    }
};