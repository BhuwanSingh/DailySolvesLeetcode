class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> found = new HashMap<Integer, Integer>();
        for( int i = 0 ; i < nums.length ; i++ ) {
            if ( found.containsKey( target - nums[i]) ) {
                return new int[]{ found.get(target - nums[i]) , i };
            }
            found.put(nums[i] , i);
        }
        return new int[]{0 , 0};
    }
}