class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zeros(n) , ones(n);
        for(int i = 0 ; i < n ; i++){
            zeros[i] = ( i > 0 ? zeros[i - 1] : 0 ) + ( s[i] == '0' ? 1 : 0);
            ones[n - i - 1] = ( i > 0 ? ones[n - i] : 0) + ( s[n - i - 1] == '1' ? 1 : 0);
        }
        int res = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            res = min(res , n - zeros[i] - ones[i]);
        }
        return res;
    }
};