class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<int> zeros(n);
        for(int i = 0 ; i < n ; i++){
            zeros[i] = s[i] == '0' ? 1 : 0;
            zeros[i] += (i > 0 ? zeros[i - 1] : 0);
            // cout << zeros[i] << " ";
        }
        int res = 1;
        for(int i = n - 1 ; i >= 0 && n - i < 60 ; i--){
            long long number = stoll( s.substr( i , n - i) , 0, 2);
            if( number <= k ){
                res = max( res , n - i + (i > 0 ? zeros[i - 1] : 0));
            } else break;
        }
        // if( stoll( s , 0, 2) <= k ) res = n;
        return res;
        // cout << "\n";
        return 0;
    }
};