class Solution {
public:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<bool>& visited,
             vector<int>& color) {
        visited[node] = true;
        color[node] = c;
        for (int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];
            if (!visited[neigh]) {
                if (!dfs(neigh, 1 - c, graph, visited, color)) {
                    return false;
                }
            } else {
                if (color[neigh] == c) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!dfs(i, 0, graph, visited, color))
                    return false;
            }
        }
        return true;
    }
};