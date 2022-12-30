class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector < string > res;
        string s = "";
        solve( 0 , n , res , n , n , s);
        return res;
    }
    
    void solve( int x , int len , vector<string>& res , int open , int close , string s){
        if( x == 2 * len ){
            res.push_back(s);
            return;
        }
        
        if( open > 0 && close >= open)
            solve( x + 1 , len , res , open - 1 , close , s + '(');
        if( close > 0 && open <= close)
            solve( x + 1 , len , res , open , close - 1 , s + ')');
    }
};