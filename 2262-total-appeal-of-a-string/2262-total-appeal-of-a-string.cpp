class Solution {
public:
    long long appealSum(string s) {
        long long res = 0;
        for(char c = 'a' ; c <= 'z' ; c++) res += get(c , s);
        return res;
    }
    
    long long get( char c , string& s){
        int n = s.size();
        long long cnt = 0 , res = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == c){
                res += ( cnt * (cnt + 1)) / 2;
                cnt = 0;
            }
            else cnt++;
        }
        res += ( cnt * (cnt + 1)) / 2;
        return ( 1ll * n * (n + 1)) / 2 - res;        
    }
};