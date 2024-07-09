class Solution {
    func averageWaitingTime(_ customers: [[Int]]) -> Double {
        var wait: Double = 0
        var cur: Double = 0

        for a in customers {
            cur = max(cur, Double(a[0])) + Double(a[1])
            wait += cur - Double(a[0])
        }

        return wait / Double(customers.count)

    }
}