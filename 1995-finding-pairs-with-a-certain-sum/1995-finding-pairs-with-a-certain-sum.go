type FindSumPairs struct {
    nums1 []int
    nums2 []int
    freq2 map[int]int
}

func Constructor(nums1 []int, nums2 []int) FindSumPairs {
    freq := make(map[int]int)
    for _, num := range nums2 {
        freq[num]++
    }
    return FindSumPairs{
        nums1: nums1,
        nums2: nums2,
        freq2: freq,
    }
}

func (this *FindSumPairs) Add(index int, val int) {
    oldVal := this.nums2[index]
    this.freq2[oldVal]--
    if this.freq2[oldVal] == 0 {
        delete(this.freq2, oldVal)
    }

    this.nums2[index] += val
    this.freq2[this.nums2[index]]++
}

func (this *FindSumPairs) Count(tot int) int {
    res := 0
    for _, num := range this.nums1 {
        complement := tot - num
        res += this.freq2[complement]
    }
    return res
}
