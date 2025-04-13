var p int64 = 1e9 + 7

func countGoodNumbers(n int64) int {
    a := n / 2
    b := n - a
    return int( power(4, a) % p * power(5, b)%p)
}

func power(x int64, y int64) int64 {
    var res int64 = 1
    x = x % p
    if x == 0 {
        return 0
    }

    for y > 0 {
        if y & 1 == 1 {
            res = (res * x) % p
        }

        y = y>>1
        x = (x*x) % p
    }
    return res
}