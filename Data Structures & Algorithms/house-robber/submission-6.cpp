class Solution {
public:
    int solveMem(vector<int>& nums,vector<int>& dp,int idx){
        if(idx==0){
            return nums[0];
        }
        if(idx<0){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=0;
        int loot=nums[idx]+solveMem(nums,dp,idx-2);
        int notloot=solveMem(nums,dp,idx-1);
        ans=max(loot,notloot);
        return dp[idx]=ans;
    }
    int solveTab(vector<int>& nums){
        vector<int> dp(nums.size()+2,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int incl=dp[i-2]+nums[i];
            int excl=dp[i-1];
            dp[i]=max(incl,excl);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp(nums.size()+1,-1);
        int n=nums.size();
        return solveMem(nums,dp,n-1);
        // return solveTab(nums);
    }
};
