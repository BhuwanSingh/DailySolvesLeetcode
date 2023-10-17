func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    
    temp := conv(x)
    
    l , r := 0 , len(temp) - 1
    
    for l < r {
        // fmt.Print( temp[l] , " " , temp[r])
        if( temp[l] != temp[r] ){
            return false
        }
        l++
        r--
    }
    return true
}

func conv(x int) string {
    res := ""
    for x > 0{
        tmp := x % 10
        x /= 10
        res += string(rune(tmp + 48))
    }
    return res
}
