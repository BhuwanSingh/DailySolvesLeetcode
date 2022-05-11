class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int n = s.size();
        
        for(int i = 0; i < n ; i++){
            char c = s[i];
            int left = i;
            int right = i;
            
            while( left >= 0 && s[left] == c) {
                left--;
            }
            while( right < n && s[right] == c){
                right++;
            }
            
            while( left >= 0 && right < n ){
                if(s[left] != s[right]){
                    break;
                }
                left--;
                right++;
            }
            left++;
            if (end - start < right - left) {
                start = left;
                end = right;
            }
        }
        
        return s.substr(start , end - start);
    }
};