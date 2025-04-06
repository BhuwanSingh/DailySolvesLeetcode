func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
        return 0
    }

    cols := len(matrix[0])
    heights := make([]int, cols)
    maxArea := 0

    for _, row := range matrix {
        for j := 0 ; j < cols ; j++ {
            if row[j] == '1' {
                heights[j] += 1
            } else {
                heights[j] = 0
            }
        }

        area := largestRectangleArea(heights)
        if area > maxArea {
            maxArea = area
        }
    }
    return maxArea
}

func largestRectangleArea(heights []int) int {
    stack := []int{}
    maxArea := 0
    n := len(heights)

    for i := 0 ; i <= n ; i++ {
        var h int
        if i == n {
            h = 0
        } else {
            h = heights[i]
        }

        for len(stack) > 0 && h < heights[stack[len(stack) - 1]] {
            top := stack[len(stack) - 1]
            stack = stack[:len(stack) - 1]
            height := heights[top]
            var width int
            if len(stack) == 0 {
                width = i
            } else {
                width = i - stack[len(stack) - 1] - 1
            }
            area := height * width
            if area > maxArea {
                maxArea = area
            }
        }
        stack = append(stack, i)
    }
    return maxArea
}