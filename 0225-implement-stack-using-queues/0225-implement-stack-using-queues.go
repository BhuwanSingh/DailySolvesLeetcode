type MyStack struct {
    arr []int
}


func Constructor() MyStack {
    return MyStack{[]int{}}
}


func (this *MyStack) Push(x int)  {
    this.arr = append(this.arr, x)
}


func (this *MyStack) Pop() int {
    n := len(this.arr)
    top := this.arr[ n - 1]
    this.arr = this.arr[:n - 1]
    return top
}


func (this *MyStack) Top() int {
    n := len(this.arr)
    return this.arr[ n - 1]
}


func (this *MyStack) Empty() bool {
    return len(this.arr) == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */