import Algorithms

class Solution {
    func xorQueries(_ arr: [Int], _ queries: [[Int]]) -> [Int] {
        let prefixXors = arr.reductions(0, ^)
        return queries.map { q in
            prefixXors[q[0]] ^ prefixXors[q[1]+1]
        }
    }
}