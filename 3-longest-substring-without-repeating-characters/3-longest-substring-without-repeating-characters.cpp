class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alp(128);
        int n = s.size();
        int left = 0;
        int res = 0;
        for(int i = 0; i < n ; i++){
            while( alp[s[i]] > 0){
                alp[s[left]] -= 1;
                left++;
            }
            alp[s[i]]++;
            res = max(res , i - left + 1);
        }
        return res;
    }
};