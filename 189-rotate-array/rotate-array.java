class Solution {
    public void rotate(int[] nums, int k) {
        int[] a = new int[nums.length];
        for( int i = 0; i < nums.length ; i++ ) {
            a[i] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[(i + k) % nums.length] = a[i];
        }
    }
}