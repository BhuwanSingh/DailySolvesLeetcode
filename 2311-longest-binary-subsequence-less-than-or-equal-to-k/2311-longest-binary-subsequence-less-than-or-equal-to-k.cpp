class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size() , zeros = 0 , num = 0 , pow2 = 1 , len = 0;
        for(auto i : s) if( i == '0') zeros++;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(num + pow2 > k) break;
            if( s[i] == '1' ) num += pow2;
            else zeros--;
            pow2 *= 2;
            len++;
        }
        return zeros + len;
    }
};