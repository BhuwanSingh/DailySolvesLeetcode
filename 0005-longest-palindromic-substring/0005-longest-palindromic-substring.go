func longestPalindrome(s string) string {
    l , r , n := 0 , 0 , len(s)
    var res string = ""

    for i := 0 ; i < n ; i++ {
        l = i
        r = i
        for l >= 0 && r < n && s[l] == s[r] {
            if( r - l + 1 > len(res)) {
                res = s[l : r + 1]
            }
            l--;
            r++;
        }
    }
    for i := 0 ; i < n ; i++ {
        l = i
        r = i + 1
        for l >= 0 && r < n  && s[l] == s[r] {
            if( r - l + 1 > len(res)) {
                res = s[l : r + 1]
            }
            l--;
            r++;
        }
    }
    return res;
}