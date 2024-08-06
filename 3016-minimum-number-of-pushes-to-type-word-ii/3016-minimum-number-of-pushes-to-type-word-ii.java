class Solution {
    public int minimumPushes(String word) {
        Map<Character , Integer> charCount = new HashMap<>();
        for(char c : word.toCharArray()){
            charCount.put(c , charCount.getOrDefault(c , 0) + 1);
        }
        
        PriorityQueue<Integer> freqHeap = new PriorityQueue<>(Collections.reverseOrder());
        freqHeap.addAll(charCount.values());
        
        int totalPresses = 0;
        int keyPositions = 0;
        
        while(!freqHeap.isEmpty()){
            totalPresses += (keyPositions / 8 + 1) * freqHeap.poll();
            keyPositions++;
        }
        
        return totalPresses;
    }
}