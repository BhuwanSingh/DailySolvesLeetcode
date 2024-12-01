func checkIfExist(arr []int) bool {
    for i := 0 ; i < len(arr) ; i++ {
        for j := 0 ; j < len(arr) ; j++ {
            if i != j && (arr[i] == (2 * arr[j])){
                return true;
            }
        }
    }
    return false;
}