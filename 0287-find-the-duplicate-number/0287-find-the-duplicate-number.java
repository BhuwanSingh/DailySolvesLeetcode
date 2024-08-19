class Solution {
    public int findDuplicate(int[] nums) {
        for(int i : nums){
            if( nums[ Math.abs(i)] < 0 ){
                return Math.abs(i);
            }
            nums[ Math.abs(i)] *= -1;
        }
        return 0;
    }
}