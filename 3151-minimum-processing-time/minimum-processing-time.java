class Solution {
    public int minProcessingTime(List<Integer> processorTime, List<Integer> tasks) {
        Collections.sort(processorTime);                   // ascending
        tasks.sort(Collections.reverseOrder());            // descending

        int res = 0;

        for (int i = 0; i < processorTime.size(); i++) {
            int base = processorTime.get(i);

            // These are 4 largest remaining tasks
            int t1 = tasks.get(4 * i);
            int t2 = tasks.get(4 * i + 1);
            int t3 = tasks.get(4 * i + 2);
            int t4 = tasks.get(4 * i + 3);

            int curr = Math.max(Math.max(base + t1, base + t2),
                                 Math.max(base + t3, base + t4));

            res = Math.max(res, curr);
        }

        return res;
    }
}
