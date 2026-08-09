class Solution {
public:
    int solveMem(int n,vector<int>& dp){
        //base case
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        int one = solveMem(n-1,dp);
        int two = solveMem(n-2,dp);
        ans=one+two;
        return dp[n]=ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);
    }
};
