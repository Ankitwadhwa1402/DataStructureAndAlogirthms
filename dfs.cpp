
const int MX = 200001;
vector<int> adj[MX];
vector<int> vis(MX);
void dfs(int S) {
    vis[S] = 1;
    for (auto& i : adj[S]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}