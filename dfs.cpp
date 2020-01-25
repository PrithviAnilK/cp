vector<bool> vis(100001, false);
vi g[100001];

// Recursive implementation of Depth First Search
void dfs(int node)
{
    vis[node] = true;

    // Process Node

    for(int child: g[node])
    {
        if(!vis[child]) dfs(child);
    }
}

void makeGraph(int n)
{
    fill(g, g+n+1, vector<int>(0));
    fill(vis.begin(), vis.end(), false);
}
