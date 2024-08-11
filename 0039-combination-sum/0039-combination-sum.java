class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(candidates, new ArrayList<>() , answer , 0 , target);
        return answer;
    }
    
    public void backtrack(int[] candidates , List<Integer> tempList, List<List<Integer>> answer , int curr , int remaining ){
        if( remaining < 0 ) return;
        else if ( remaining == 0 ) answer.add(new ArrayList<>(tempList));
        else {
            for(int i = curr ; i < candidates.length ; i++){
                tempList.add(candidates[i]);
                backtrack(candidates, tempList , answer , i , remaining - candidates[i]);
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}