class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        if( k > n / 2){
            int ans = 0;
            for(int i = 1 ; i < n ; i++){
                ans += max(prices[i] - prices[i - 1] , 0);
            }
            return ans;
        }
        int hold[k + 1];
        int rel[k + 1];
        for(int i = 0; i <= k ; i++){
            hold[i] = INT_MIN;
            rel[i] = 0;
        }
        int cur;
        for(int i = 0; i < n ; i++){
            cur = prices[i];
            for(int j = k ; j > 0 ; j--){
                rel[j] = max(rel[j] , hold[j] + cur);
                hold[j] = max(hold[j], rel[j-1] - cur);
            }
        }
        return rel[k];
    }
};