class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back() != 9){
            digits.back()++;
            return digits;
        }
        else{
            int n = digits.size();
            for(int i = n - 1 ; i >= 0 ; i--){
                if( digits[i] == 9){
                    digits[i] = 0;
                } else {
                    digits[i]++;
                    return digits;
                }
            }
            if(digits[0] == 0){
                digits.insert(digits.begin() , 1);
            }
            return digits;
        }        
    }
};