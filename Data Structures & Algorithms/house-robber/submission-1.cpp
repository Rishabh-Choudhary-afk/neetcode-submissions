class Solution {
public:
    int solveMem(vector<int>& nums,vector<int>& dp,int idx){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=0;
        int loot=nums[idx]+solveMem(nums,dp,idx+2);
        int notloot=solveMem(nums,dp,idx+1);
        ans=max(loot,notloot);
        return dp[idx]=ans;
    }
    int solveTab(vector<int>& nums){
        vector<int> dp(nums.size()+2,0);
        for(int idx=nums.size()-1;idx>=0;idx--){
            int ans=0;
            int loot=nums[idx]+dp[idx+2];
            int notloot=dp[idx+1];
            ans=max(loot,notloot);
            dp[idx]=ans;
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,-1);
        // return solveMem(nums,dp,0);
        return solveTab(nums);
    }
};
