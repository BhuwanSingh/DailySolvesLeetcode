func isHappy(n int) bool {
    mp := map[int]int{}

    for {
        if n == 1 {
            break
        }
        mp[n] = 1
        temp := 0
        for n > 0 {
            one := n % 10
            temp += one * one
            n /= 10
        }
        n = temp
        if _, found := mp[n]; found {
            return false
        }
    }
    return true
}