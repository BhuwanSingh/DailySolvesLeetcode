class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
        return combos( s , p , 0 , 0 , dp);
    }
    
    bool combos(string& s , string& p , int x , int y , vector<vector<int>>& dp){
        int n = s.size() , m = p.size();
        if( dp[x][y] != -1)
            return dp[x][y];
        
        if( y >= m ) return x >= n;
        bool res;                
        if( p[y + 1] == '*'){
            res = combos(s , p , x , y + 2 , dp ) || x < n && (s[x] == p[y] || p[y] == '.') && combos(s , p , x + 1 , y , dp);
        } else {
            res = x < n && ( s[x] == p[y] || '.' == p[y] ) && combos(s , p , x + 1 , y + 1 , dp );
        }
        
        return dp[x][y] = res;
    }
};