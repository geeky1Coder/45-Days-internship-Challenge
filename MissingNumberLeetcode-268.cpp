class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sm=0;
        int n=nums.size();
        int xm=((n)*(n+1))/2;
        for(auto el:nums){
            sm+=el;
        }
        
        return (xm-sm);
    }
};