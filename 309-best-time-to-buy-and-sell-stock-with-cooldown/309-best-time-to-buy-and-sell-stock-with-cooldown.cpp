class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n == 0 ) return 0;
        
        vector<int> mem(n);
        
        int maxdiff = INT_MIN;
        for(int i = 0; i < n ; i++){
            if( i < 2 ) maxdiff = max(maxdiff , -prices[i]);
            if( i == 0 ) mem[0] = 0;
            else if( i == 1) mem[i] = max(0 , prices[1] - prices[0]);
            else {
                mem[i] = max(mem[i - 1] , prices[i] + maxdiff);
                maxdiff = max( maxdiff , mem[i - 2] - prices[i]);
            }
        }
        return mem[n - 1];
    }
};