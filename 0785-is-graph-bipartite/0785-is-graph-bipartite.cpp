class Solution {
public:
    bool valid(vector<vector<int>>& graph, vector<int>& color, int c,
               int node) {
        color[node] = c;
        for (int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];
            if (color[neigh] == -1) {
                if (!valid(graph, color, 1 - c, neigh))
                    return false;
            } else if (color[neigh] == c) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (!valid(graph, color, 1, i))
                    return false;
            }
        }
        return true;
    }
};