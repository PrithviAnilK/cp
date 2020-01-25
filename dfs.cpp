bool vis(100001, 0);
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