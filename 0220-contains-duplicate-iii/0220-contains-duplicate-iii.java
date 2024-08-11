import java.util.TreeSet;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        if (nums == null || nums.length == 0 || indexDiff <= 0 || valueDiff < 0) {
            return false;
        }

        TreeSet<Long> set = new TreeSet<>();

        for (int i = 0; i < nums.length; i++) {
            // Convert the number to long to handle potential overflow
            long current = (long) nums[i];

            // Find the smallest number >= (current - valueDiff)
            Long floor = set.floor(current + valueDiff);
            // Find the largest number <= (current + valueDiff)
            Long ceiling = set.ceiling(current - valueDiff);

            if ((floor != null && floor >= current) || (ceiling != null && ceiling <= current)) {
                return true;
            }

            set.add(current);

            // Keep the set within the indexDiff window
            if (i >= indexDiff) {
                set.remove((long) nums[i - indexDiff]);
            }
        }

        return false;
    }
}
