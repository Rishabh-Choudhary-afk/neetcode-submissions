class Solution {
public:
    int solveMem(vector<int>& cost,int idx,vector<int>& dp){
        //base case
        if(idx>=cost.size()){
            return 0;
        }
        if(idx==cost.size()-1){
            return cost[idx];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=0;
        int one=cost[idx]+solveMem(cost,idx+1,dp);
        int two=cost[idx]+solveMem(cost,idx+2,dp);
        ans=min(one,two);
        return dp[idx]=ans;

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp1(cost.size()+1,-1);
        vector<int> dp2(cost.size()+1,-1);
        int a=solveMem(cost,0,dp1);
        int b=solveMem(cost,1,dp2);
        return min(a,b);
    }
};
