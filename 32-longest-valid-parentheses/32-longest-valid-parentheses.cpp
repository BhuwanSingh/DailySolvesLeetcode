class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);
        int maxval = 0;
        for(int i = 1; i < n ; i++){
            if(s[i] == ')'){
                if( s[i - 1] == '('){
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                } else {
                    if( i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '('){
                        dp[i] = dp[i - 1] + 2 + ( i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                    }
                }
            } 
            maxval = max(maxval , dp[i]);
        }
        return maxval;
    }
};