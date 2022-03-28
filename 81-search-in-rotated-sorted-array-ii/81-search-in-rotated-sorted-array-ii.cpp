class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int is_avail = false;
        for(int i = 0; i < nums.size() ; i++){
            if(nums[i] == target){
                is_avail = true;
                break;
            }
        }
        return is_avail;
    }
};