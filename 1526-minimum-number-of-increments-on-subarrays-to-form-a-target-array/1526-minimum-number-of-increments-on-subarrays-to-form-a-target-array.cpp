class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size() , res = 0 , pre = 0;        
        for(int i = 0 ; i < n ; i++ ){
            res += max(target[i] - pre , 0);
            pre = target[i];
        }
        return res;
    }
};