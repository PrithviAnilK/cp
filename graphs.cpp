#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 1;
vector<int> g[mxN];
vector<bool> vis;
vector<int> d;

/*
	Takes arguments number of nodes, number of edges,
	Makes a graph.
*/
void makeGraph(int n, int e)
{
	fill(g, g + n + 1, vector<int>(0));
	d = vector<int>(n + 1, INT_MAX);
	vis = vector<bool>(n + 1, false);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

// Recursive implementation of Depth First Search
void dfs(int node)
{
	vis[node] = true;
	// Process Node
	for (int child : g[node]) {
		if (!vis[child])
			dfs(child);
	}
}

/*
	Takes in the number of nodes as an argument,
	Returns the number of connected components in a undirected graph.
*/
int countConectedComponents(int n)
{
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			c++;
		}
	}
	return c;
}

/* Classic breadth first search algorithm */
void bfs(int node)
{
	queue<int> q;
	d[node] = 0;
	vis[node] = 1;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int child : g[node]) {
			if (vis[child])
				continue;
			vis[child] = 1;
			d[child] = d[node] + 1;
			q.push(child);
		}
	}
}