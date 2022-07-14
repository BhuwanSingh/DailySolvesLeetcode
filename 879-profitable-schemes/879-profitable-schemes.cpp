class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        memset(memo, -1, sizeof(int)*101*101*101);
        return dfs(G, P, group, profit, group.size()-1);
    }
private:
    int memo[101][101][101];
    long long mod = 1e9+7;
    long long dfs(int g, int p, vector<int>& group, vector<int>& profit, int index) {
        if (index == -1) {
            if (p <= 0) return 1;
            else return 0;
        }
        if (memo[g][p][index] != -1) return memo[g][p][index];
        // not use index
        long long res = dfs(g, p, group, profit, index-1) % mod;
        // use index
        if (g >= group[index]) {
            res += dfs(g-group[index], max(0, p-profit[index]), group, profit, index-1) % mod;
        }
        memo[g][p][index] = res % mod;
        return memo[g][p][index];
    }
};