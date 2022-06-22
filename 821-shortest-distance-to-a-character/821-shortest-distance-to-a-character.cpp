class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size() , temp = 1e5;
        vector<int> ans(n);
        for(int i = 0; i < n ; i++){
            if(s[i] == c){
                temp = 0;
            } else temp++;
            ans[i] = temp;
        }
        temp = 1e5;
        for(int i = n - 1; i >= 0 ; i--){
            if(s[i] == c){
                temp = 0;
            } else temp++;
            ans[i] = min(temp , ans[i]);
        }
        return ans;
    }
};