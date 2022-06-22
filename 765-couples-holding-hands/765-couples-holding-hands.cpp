class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> parent(n);
        // for(int i = 0; i < n ; i++) parent[i] = i;
        for(int i = 0; i < n ; i += 2 ){
            parent[row[i]] = row[i];
            parent[row[i + 1]] = row[i];
        }
        int cycles = 0;
        
        for(int i = 0; i < n ; i += 2 ){
            int px = find(parent , i) , py = find(parent , i + 1);
            if( px != py ){
                // cout << px << " " << py << " ";
                cycles++;
                uni(parent , i , i + 1);
            }
        }
        // cout << "=\n";
        return cycles;
    }
    
    void uni(vector<int>& parent , int x , int y){
        int px = find(parent , x);
        int py = find(parent , y);
        if( px != py ){
            parent[py] = px;
        }
    }
    
    int find(vector<int>& parent , int x){
        while( parent[x] != x)  x = parent[x];
        return x;
    }
};