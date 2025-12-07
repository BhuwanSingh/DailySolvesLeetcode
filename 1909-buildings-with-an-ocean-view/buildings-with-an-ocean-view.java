class Solution {
    public int[] findBuildings(int[] heights) {
        int n = heights.length;
        int currMax = heights[n - 1];
        ArrayList<Integer> res = new ArrayList<>();
        res.add(n - 1);
        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            if ( currMax < heights[i] ) {
                res.add(i);
            }
            currMax = Math.max(currMax, heights[i]);
        }
        int[] ans = new int[res.size()];
        int i = res.size() - 1;
        for( Integer it : res) {
            ans[i] = it;
            i--;
        }
        return ans;
    }
}