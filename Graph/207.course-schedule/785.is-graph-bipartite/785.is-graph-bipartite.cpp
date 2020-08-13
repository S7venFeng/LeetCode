class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int now, vector<int> &isVisited, int color) {
        if (isVisited[now] != 0) {
            return isVisited[now] == color;
        }
        isVisited[now] = color;
        for (auto x : graph[now]) {
            if (dfs(graph, x, isVisited, -color) == false) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> isVisited(graph.size(), 0);
        for (int i = 0; i < graph.size(); ++i) {
            int color = 1;
            if (0 == isVisited[i]) {
                if (dfs(graph, i, isVisited, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};