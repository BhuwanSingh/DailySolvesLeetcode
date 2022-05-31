class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        vector<bool> nums( 1<<k , false);
        for(int i = 0; i < n - k  + 1; i++ ){
            int rn = conv(s.substr(i , k));
            nums[rn] = true;
        }
        for(auto i : nums){
            if( i == false ) return false;
            // cout << i << " ";
        }
        // cout << "\n";
        return true;
    }
    
    int conv(string inp){
        int res = 0;
        for(int i = 0 ; i < inp.size() ; i++){
            res *= 2;
            res += (inp[i] - '0');
        }
        return res;
    }
};