class Solution {
public:
    int titleToNumber(string c) {
        int res = 0;
        int n = c.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            res += (c[i] - 'A' + 1) * pow(26 , n - 1 - i);
        }
        return res;
    }
};