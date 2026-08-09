class Solution {
public:
    int solveMem(vector<int>& nums,vector<int>& dp,int idx,int end){
        if(idx>=end){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=0;
        int loot=nums[idx]+solveMem(nums,dp,idx+2,end);
        int notloot=solveMem(nums,dp,idx+1,end);
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
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        return max(solveMem(nums,dp1,0,n-1),solveMem(nums,dp2,1,n));
        // return solveTab(nums);
    }
};
