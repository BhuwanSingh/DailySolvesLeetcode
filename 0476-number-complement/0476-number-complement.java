class Solution {
    public int findComplement(long num) {
        long twoth = 1;
        while( twoth <= num){
            twoth = twoth << 1;
        }
        twoth -= 1;
        System.out.println(twoth);
        return (int)(twoth ^ num);
    }
}