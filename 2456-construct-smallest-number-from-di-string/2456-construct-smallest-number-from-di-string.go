func smallestNumber(s string) string {
    var res, stack string
    for i := 0 ; i <= len(s) ; i++ {
        // stack = append(stack , '1' + 1)
        stack += string('1' + i)
        if i == len(s) || s[i] == 'I' {
            for stack != "" {
                // res = append(res , stack[len(stack) - 1])
                res += string(stack[len(stack) - 1])
                stack = stack[:len(stack) - 1]
            }
        }
    }
    return res
}