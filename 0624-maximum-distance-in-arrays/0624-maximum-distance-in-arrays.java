class Solution {
    public int maxDistance(List<List<Integer>> arrays) {
        int minValue = arrays.get(0).get(0);
        int maxValue = arrays.get(0).get(arrays.get(0).size() - 1);
        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            List<Integer> l = arrays.get(i);
            // Calculate possible max distance with the current list's first and last elements
            result = Math.max(result, Math.abs(l.get(l.size() - 1) - minValue));
            result = Math.max(result, Math.abs(maxValue - l.get(0)));

            // Update minValue and maxValue
            minValue = Math.min(minValue, l.get(0));
            maxValue = Math.max(maxValue, l.get(l.size() - 1));
        }

        return result;
    }
}
