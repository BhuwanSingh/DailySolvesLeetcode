type ProductOfNumbers struct {
    prefixProducts []int
}


func Constructor() ProductOfNumbers {
    return ProductOfNumbers {
        prefixProducts: []int{1},
    }
}


func (this *ProductOfNumbers) Add(num int)  {
    if num == 0 {
        this.prefixProducts = []int{1}
    } else {
        this.prefixProducts = append(
            this.prefixProducts,
            this.prefixProducts[len(this.prefixProducts)-1]*num,
        )
    }
}


func (this *ProductOfNumbers) GetProduct(k int) int {
    n := len(this.prefixProducts)
	if k >= n {
		return 0
	}
	return this.prefixProducts[n-1] / this.prefixProducts[n-k-1]
}


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(num);
 * param_2 := obj.GetProduct(k);
 */