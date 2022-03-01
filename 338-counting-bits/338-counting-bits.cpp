class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> v(n + 1);
        v[0] = 0;
        v[1] = 1;
        for(int i = 2; i <= n ; i += 2){
            v[i] = v[i / 2];
            if(i + 1 <= n ) v[i + 1] = v[i / 2] + 1;
        }
        return v;
    }
};