class Solution {
    public int jump(int[] nums) {
        int answer = 0, n = nums.length;
        int curEnd = 0, curFar = 0;

        for ( int i = 0; i < n - 1 ; i++ ) {
            curFar = Math.max( curFar , nums[i] + i);

            if ( i == curEnd ) {
                answer++;
                curEnd = curFar;
            }
        }

        return answer;
    }
}