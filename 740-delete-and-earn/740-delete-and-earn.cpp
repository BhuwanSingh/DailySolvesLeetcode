class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int ,int> ms;
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            ms[nums[i]]++;
        }
        vector<pair<int , int>> ves = vector<pair<int , int>>(ms.begin() , ms.end());
        int m = ves.size();
        vector<int> dp(m + 1);
        dp[1] = ves[0].first * ves[0].second; 
        for(int i = 1; i < m ; i++){
            // cout << ves[i].first << " " << ves[i].second << "\n";
            if( ves[i].first - ves[i - 1].first == 1){
                dp[i + 1] = max( dp[i] , dp[i - 1] + ves[i].first * ves[i].second);
            } else {
                dp[i + 1] = dp[i] + ves[i].first * ves[i].second;
            }
        }
        return dp[m];
    }
};