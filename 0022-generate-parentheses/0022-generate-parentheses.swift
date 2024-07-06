class Solution {
    func generateParenthesis(_ n: Int) -> [String] {
        var result = [String]()
        backtrack("",0,0,n){
            result.append($0)
        }
        return result
    }
    
    func backtrack( _ current : String, _ open: Int, _ end: Int , _ max : Int, _ result: (String) -> Void ){
        if current.count == max * 2 {
            result(current)
            return
        }
        
        if open < max { backtrack(current + "(" , open + 1 , end , max , result )}
        if end < open { backtrack(current + ")" , open , end + 1 , max , result )}
    }
}