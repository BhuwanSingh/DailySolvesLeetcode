func maxArea(height []int) int {
    left := 0;
    right := len(height) - 1;
    
    res := 0.0;
    
    for right >= left  {
        if height[left] < height[right] {
            res = math.Max( res , float64((right - left) * height[left]))
            left++;
        } else {
            res = math.Max( res, float64((right - left) * height[right]))
            right--;
        }
    }
    
    return int(res);
}