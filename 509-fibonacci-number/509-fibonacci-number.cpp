class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int a = 1 , b = 1;
        for(int i = 3 ; i <= n ; i++){
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};