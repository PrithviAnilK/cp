vector<bool> vis(100001, false);
vi g[100001];


/* 
    Takes arguments number of nodes, number of edges,
    Makes a graph.
*/
void makeGraph(int n, int e)
{
    fill(g, g+n+1, vector<int>(0));
    fill(vis.begin(), vis.end(), false);
    for(int i = 0;i < e;i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        g[node1].push_back(node2);
        g[node2].push_back(node1);
    }
}


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


/*
    Takes in the number of nodes as an argument,
    Returns the number of connected components in a undirected graph. 
*/
int countConectedComponents(int n)
{
    int c = 0;
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i]) 
        {
            dfs(i);
            c++;
        }
    }
    return c;
}