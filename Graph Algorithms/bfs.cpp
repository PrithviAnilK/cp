vi g[100001];
vector<bool> vis(100001, false);
vector<int> d(100001, INT_MAX);


/* 
    Takes arguments number of nodes, number of edges,
    Makes a graph.
*/
void makeGraph(int n, int e)
{
    fill(g, g+n+1, vector<int>(0));
    fill(all(d), INT_MAX);
    fill(all(vis), false);
    for(int i = 0;i < e;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
}


/* Classic breadth first search algorithm */
void bfs(int node)
{
    queue<int> q;
    d[node] = 0;
    vis[node] = 1;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for(int child: g[node])
        {
            if(vis[child]) continue;
            // cout << child << " ";
            vis[child] = 1;
            d[child] = d[node] + 1;
            q.push(child);
        }
    }
}
