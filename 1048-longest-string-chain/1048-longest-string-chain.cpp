class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();        
        sort(words.begin() , words.end() , [](string& a , string& b){
            if( a.size() != b.size() ){
                return a.size() < b.size() ;
            } else return a < b;
        });
        vector<int> dp(n , 1);
        for(int i = 0 ; i < n ; i++){            
            for(int j = 0 ; j < i ; j++){
                if( check(words[j] , words[i]) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        return *max_element(dp.begin() , dp.end());
    }
    
    bool check( string& w1 , string& w2){
        int n = w1.size() , m = w2.size();
        if(m - n != 1) return false;
        int i = 0 , j = 0;
        bool once = false;
        while( i < n && j < m){
            if( w1[i] == w2[j]){
                i++ , j++;
            } else if (!once){
                once = true;
                j++;
            } else return false;
        }
        return true;
    }
};