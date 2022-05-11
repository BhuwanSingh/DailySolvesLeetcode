class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i = 0; i < n ; i++){
            int l , r;
            // odd
            l = i;
            r = i;
            while( l >= 0 && r < n && s[l] == s[r]){
                if(res.size() < r - l + 1){
                    res = s.substr( l  , r - l + 1);
                }
                l-- , r++;
            }
            
            // even
            l = i;
            r = i + 1;
            while( l >= 0 && r < n && s[l] == s[r] ){
                if(res.size() < r - l + 1){
                    res = s.substr( l , r - l + 1 );
                }
                l-- , r++;
            }
            
        }
        return res;
    }
};