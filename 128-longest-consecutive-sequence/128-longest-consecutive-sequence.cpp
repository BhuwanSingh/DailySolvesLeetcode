class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s = unordered_set<int>(nums.begin() , nums.end());
        int res = 0;
        for(auto i : nums){
            if( s.find(i) == s.end() ) continue;
            int prev = i - 1 , next = i + 1;
            s.erase(i);
            while(s.find(prev) != s.end()) s.erase(prev--);
            while(s.find(next) != s.end()) s.erase(next++);
            res = max(res , next - prev - 1);
        }
        return res;
    }
};