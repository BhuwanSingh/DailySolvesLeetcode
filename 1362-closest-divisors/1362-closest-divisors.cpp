class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> a = get(num + 1) , b = get(num + 2);
        if( abs(a[0] - a[1]) < abs( b[0] - b[1] )) return a;
        else return b;
    }
    
    vector<int> get(int num){
        for(int i = sqrt(num) ; i >= 1 ; i--){
            if( num % i == 0){
                return {i , num / i};
            }
        }
        return { 1 , num };
    }
};