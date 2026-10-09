class Solution {
public:
    bool fun(vector<vector<int>>& graph, vector<int>& col, vector<bool>& vis,
             int node, int c) {
        vis[node] = true;
        if (col[node] == -1) {
            col[node] = c;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if (vis[neighbour]) {
                if (col[neighbour] == c)
                    return false;
            } else {
                if (!fun(graph, col, vis, neighbour, 1 - c))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!fun(graph, col, vis, i, 0))
                    return false;
            }
        }
        return true;
    }
};