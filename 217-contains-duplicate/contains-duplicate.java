class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> hm = new HashSet<Integer>();

        for (int n : nums ) {
            if ( hm.contains(n) ) {
                return true;
            }
            hm.add(n);
        }
        return false;
    }
}