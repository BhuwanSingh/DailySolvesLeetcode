func isPalindrome(num int) bool {
    if num < 0 {
        return false
    }
    x := num
    reversed := 0
    for x != 0 {
        reversed = 10*reversed + x%10
        x /= 10
    }
    return (reversed == num)
}