class Solution {
    public int strStr(String haystack, String needle) {
        int n = haystack.length() , m = needle.length();

        for(int i = 0 ; i <= n - m ; i++){
            if( haystack.substring(i , i + m).equals(needle) ){
                return i;
            }
            // System.out.println(haystack.substring(i , i + m));
        }

        return -1;
    }
}