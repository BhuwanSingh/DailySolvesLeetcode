class Solution {
    public int removeElement(int[] nums, int val) {
        int right = nums.length - 1;
        for ( int i = 0 ; i <= right ; i++) {
            while(right >= 0 && nums[right] == val) {
                right--;
            }
            if (nums[i] == val && right >= i) {
                int temp = nums[i];
                nums[i] = nums[right];
                nums[right] = temp;
            }
            // for( int x : nums) {
            //     System.out.print(x + " ");
            // }
            // System.out.println(i + " " + right);
        }
        return right + 1;
    }
}