class Solution {
    public boolean isPalindrome(int x) {
        if ( x < 0 ){
            return false;
        }
        char[] str = Integer.toString(x).toCharArray();
        int l = 0, r = str.length - 1;
        while ( l < r ) {
            if ( str[l] != str[r] ){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}