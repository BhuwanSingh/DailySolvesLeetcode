class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> stv = {
            { 'I' , 1 },
            { 'V' , 5 },
            { 'X' , 10 },
            { 'L' , 50 },
            { 'C' , 100 },
            { 'D' , 500 },
            { 'M' , 1000 }
        };
        
        int res = stv[s.back()];
        
        for(int i = s.length() - 2 ; i >= 0 ; i--){
            if( stv[s[i]] < stv[s[i + 1]]){
                res -= stv[s[i]];
            } else {
                res += stv[s[i]];
            }
        }
        
        return res;
    }
};