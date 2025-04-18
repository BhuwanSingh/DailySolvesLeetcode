func trap(height []int) int {
    n := len(height)
    left, right := 0 , n - 1
    res := 0
    maxleft, maxright := 0 , 0
    for left <= right {
        if height[left] <= height[right] {
            if height[left] >= maxleft {
                maxleft = height[left]
            } else {
                res += maxleft - height[left]
            }
            left++
        } else {
            if height[right] >= maxright {
                maxright = height[right]
            } else {
                res += maxright - height[right]
            }
            right--
        }
    }
    return res
}