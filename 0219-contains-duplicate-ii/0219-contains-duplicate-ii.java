class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> hs = new HashMap<>();
        
        for(int i = 0; i < nums.length ; i++){
            if( hs.containsKey(nums[i]) ){
                Integer itr = hs.get(nums[i]);
                if( i - itr <= k) {
                    return true;
                }
            }
            hs.put(nums[i] , i);
        }
        return false;
    }
}