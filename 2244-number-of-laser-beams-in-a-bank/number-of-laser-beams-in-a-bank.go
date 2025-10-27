func numberOfBeams(bank []string) int {
    res := []int{}
    for _, val := range bank {
        num := cal(val)
        if num != 0{
            res = append(res, num)
        }
    }
    result := 0
    for i := 1 ; i < len(res) ; i++ {
        result += res[i] * res[i - 1]
    }
    return result
}

func cal(str string) int {
    res := 0
    for _, val := range str {
        if val == '1' {
            res++
        }
    }
    return res
}