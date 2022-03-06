class Solution {
public:
    int countOrders(int n) {
        long long int M = 1e9 + 7;
        long long int res = 1;
        for(int i = 2 * n; i >= 2 ; i -= 2){
            res *= ( 1ll * (i * (i - 1))) / 2;
            res %= M;
        }
        return int(res);
    }
};