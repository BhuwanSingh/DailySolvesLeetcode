func longestPalindrome(s string) int {
    cnt := [128]int{}
    for _, c := range s {
        cnt[c]++
    }
    
    ans := 0
    for _, v := range cnt {
        ans += v - (v & 1)
        if ans % 2 == 0 && v % 2 == 1 {
            ans++
        }
    }
    return ans
}