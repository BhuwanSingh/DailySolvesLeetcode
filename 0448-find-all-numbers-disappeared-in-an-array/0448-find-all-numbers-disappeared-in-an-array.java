class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        
        // Mark elements as negative to indicate their presence
        for (int c : nums) {
            int index = Math.abs(c) - 1;
            nums[index] = -Math.abs(nums[index]);
        }
        
        // Find the indices which are positive, these indices + 1 are the missing numbers
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                ans.add(i + 1);
            }
        }
        
        return ans;
    }
}
