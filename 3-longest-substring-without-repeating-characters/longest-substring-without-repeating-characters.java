class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> charToNextIndex = new HashMap<>();

        for ( int j = 0 , i = 0 ; j < n ; j++ ) {
            if ( charToNextIndex.containsKey(s.charAt(j)) ) {
                i = Math.max(charToNextIndex.get(s.charAt(j)) , i);
            }
            ans = Math.max( ans, j - i + 1);
            charToNextIndex.put(s.charAt(j) , j + 1);
        }
        return ans;
    }
}