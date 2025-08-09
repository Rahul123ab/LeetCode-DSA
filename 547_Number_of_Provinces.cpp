class Solution {
public:
    unordered_set<int> visited;

    void dfs(vector<vector<int>>& isConnected, int i) {
        visited.insert(i);

        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[i][j] == 1 && visited.count(j) == 0) {
                dfs(isConnected, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) { //TC=O(n^2), SC=O(n)
        int provinces = 0;
        int n = isConnected.size();

        for(int i = 0; i < n; i++) {
            if(visited.count(i) == 0) {
                provinces += 1;
                dfs(isConnected,i);
            }
        }
        return provinces;
    }
};