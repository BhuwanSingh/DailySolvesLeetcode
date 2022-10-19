class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0; i < n ; i++){
            int l = i ,r = i;
            while( l >= 0 && r < n && s[l] == s[r] ){
                if( res.size() < r - l + 1){
                    res = s.substr(l , r - l + 1);
                }
                l--;
                r++;
            }
        }
        for(int i = 1; i < n ; i++){
            int l = i - 1 , r = i;
            while( l >= 0 && r < n && s[l] == s[r] ){
                if( res.size() < r - l + 1){
                    res = s.substr(l , r - l + 1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};