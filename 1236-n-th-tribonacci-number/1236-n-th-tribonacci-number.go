func tribonacci(n int) int {
    if n == 0 {
        return 0
    } else if n == 1 || n == 2{
        return 1
    }

    a , b , c := 0, 1, 1

    for i := 4 ; i <= n + 1 ; i++ {
        a , b , c = b , c , a + b + c
    }

    return c
}