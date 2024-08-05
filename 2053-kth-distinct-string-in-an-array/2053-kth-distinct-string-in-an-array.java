class Solution {
    public String kthDistinct(String[] arr, int k) {
        Set<String> distinct = new HashSet<>();
        Set<String> seen = new HashSet<>();
        
        for(String str : arr){
            if(seen.contains(str)){
                distinct.remove(str);
            } else {
                seen.add(str);
                distinct.add(str);
            }
        }
        
        for(String str : arr){
            if( distinct.contains(str) && --k == 0){
                return str;
            }
        }
        
        return "";
    }
}