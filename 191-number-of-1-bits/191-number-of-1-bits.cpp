class Solution {
public:
    int hammingWeight(uint32_t n) {        
        int res = 0;
        while(n){
            int temp = n % 2;
            if(temp == 1) res++;
            n /= 2;
        }
        return res;
    }
};