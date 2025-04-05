type StockSpanner struct {
    arr [][2]int
}


func Constructor() StockSpanner {
    return StockSpanner{}
}


func (ss *StockSpanner) Next(price int) int {
    out := 1
    for len(ss.arr) > 0 && ss.arr[len(ss.arr) - 1][1] <= price {
        out += ss.arr[len(ss.arr) - 1][0]
        ss.arr = ss.arr[:len(ss.arr) - 1]
    }
    ss.arr = append(ss.arr, [2]int{out, price})
    return out
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */