class Solution {
public:
    int countVowelStrings(int n) {
        vector<char> vowels = { 'a' , 'e' , 'i' , 'o' , 'u'};
        int count = 0;
        combos(vowels , count , n,  0);
        return count;
    }
    
    void combos(vector<char>& vowels , int& count , int n , int itr){
        if(n == 0){
            count++;
            return;
        }
        for(int i = itr; i < 5 ; i++){
            combos(vowels , count , n - 1 , i);
        }
        return;
    }
};