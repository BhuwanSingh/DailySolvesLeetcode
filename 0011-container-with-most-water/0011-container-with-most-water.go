func maxArea(height []int) int {
    i , j := 0 , len(height) - 1
    res := 0
    for ; i <= j; {
        if( height[i] < height[j] ){
            res = int( max(float64(res) , float64(height[i] * ( j - i ) )))
            i++
        } else {
            res = int( max(float64(res) , float64(height[j] * ( j - i ) )))
            j--
        }
    }
    return res
}