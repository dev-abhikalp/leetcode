class Solution {
public:
int solve(int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){ // Have I already calculated solve(n), if YES -> fetch it ( dp[i]=answer to solve(i) )
        return dp[n];
    }

    int one_step=solve(n-1,dp);
    int two_step=solve(n-2,dp);
    dp[n]= one_step+two_step;

    return dp[n];
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};