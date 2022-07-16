class Solution {
public:
    int dp[367];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp , -1 , sizeof(dp));
        return solve(days , costs , 0 );
    }
    
    int solve(vector<int>& days, vector<int>& costs , int x ){
        if( x >= days.size() ){
            return 0;
        }
        
        if( dp[x] != -1)
            return dp[x];
        
        int a[3] = { 1 , 7 , 30};
        int res = INT_MAX;
        for(int i = 0; i < 3 ; i++){
            auto itr = lower_bound( days.begin() , days.end() , days[x] + a[i]);
            res = min( res , solve(days , costs , itr - days.begin()) + costs[i] );
        }
        
        return dp[x] = res;
    }
};