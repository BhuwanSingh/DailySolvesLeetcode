func maximumTripletValue(nums []int) int64 {
    var res int64 = 0
    maxa , maxab := 0 , 0
    for _, a := range(nums) {
        res = max(res , int64(maxab * a))
        maxab = max(maxab, maxa - a)
        maxa = max(maxa , a)
    }
    return res
}