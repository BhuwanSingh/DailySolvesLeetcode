/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int minnum = 1 , maxnum = n;
        while( true ){
            int avg = (maxnum - minnum) / 2 + minnum;
            int test = guess(avg);
            if( test == 0){
                return avg;
            } else if ( test == 1 ){
                minnum = avg + 1;
            } else {
                maxnum = avg - 1;
            }
        }
        return minnum;
    }
};