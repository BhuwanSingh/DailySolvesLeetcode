class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int comp = 0;
        int sum = 0;
        int res = 0;
        for(int i = 0; i < n ; i++){
            comp += i;
            sum += arr[i];
            if(comp == sum) res++;
        }
        return res;
    }
};