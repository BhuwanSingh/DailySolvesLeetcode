class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> temp = nums;
        sort( temp.begin() , temp.end());
        if( temp == nums) return true;
        sort( temp.rbegin() , temp.rend());
        if( temp == nums) return true;
        return false;
    }
};