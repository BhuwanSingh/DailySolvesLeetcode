func distributeCandies(n int, limit int) int64 {
    C2 := func(x int64) int64 {
        if x >= 2 {
            return x * (x - 1) / 2
        }
        return 0
    }
    N := int64(n)
    L := int64(limit)
    total := (N + 2) * (N + 1) / 2
    x1 := N - L + 1
    t1 := C2(x1)
    x2 := N - 2*L
    t2 := C2(x2)
    x3 := N - 3*L - 1
    t3 := C2(x3)
    return total - 3 * t1 + 3 * t2 - t3
}