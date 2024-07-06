class Solution {
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()

        for c in s {
            if c == "{" {
                stack.append("}")
            } else if c == "(" {
                stack.append(")")
            } else if c == "[" {
                stack.append("]")
            } else if stack.isEmpty || stack.removeLast() != c {
                return false
            }
        }
        
        return stack.isEmpty
    }
}