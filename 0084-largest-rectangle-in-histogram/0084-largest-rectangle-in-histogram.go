package main

import (
	"fmt"
)

func largestRectangleArea(heights []int) int {
	nsr := nsr(heights)
	nsl := nsl(heights)

	res := 0
	for i, val := range heights {
		width := nsr[i] - nsl[i] - 1
		res = max(res, val*width)
	}
	return res
}

func nsr(arr []int) []int {
	n := len(arr)
	stack := []int{}
	res := make([]int, n)

	for i := n - 1; i >= 0; i-- {
		for len(stack) > 0 && arr[stack[len(stack)-1]] >= arr[i] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) == 0 {
			res[i] = n
		} else {
			res[i] = stack[len(stack)-1]
		}

		stack = append(stack, i)
	}

	return res
}

func nsl(arr []int) []int {
	n := len(arr)
	stack := []int{}
	res := make([]int, n)

	for i := 0; i < n; i++ {
		for len(stack) > 0 && arr[stack[len(stack)-1]] >= arr[i] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) == 0 {
			res[i] = -1
		} else {
			res[i] = stack[len(stack)-1]
		}

		stack = append(stack, i)
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
