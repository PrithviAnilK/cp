#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LOG = 17;  // assume log (N) <= 17

class binary_lifting {
 private:
  vector<vector<int>> graph;
  vector<vector<int>> up;
  vector<int> depth;

  // run dfs(root, root)
  void dfs(int node, int parent) {
    if (node != parent) {
      depth[node] = depth[parent] + 1;
    }
    up[node][0] = parent;
    for (int i = 1; i <= LOG; ++i) {
      up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for (int child : graph[node]) {
      if (child != parent) {
        dfs(child, node);
      }
    }
  }

 public:
  binary_lifting(vector<vector<int>> graph) : graph(graph) {
    int n = graph.size() + 1;  // assume 0 <= node value <= n
    up.assign(n, vector<int>(LOG, 0));
    depth.assign(n, 0);
  }

  int kth_ancestor(int node, int k) {
    if (depth[node] < k) {
      return -1;
    }
    for (int i = 0; i <= LOG; ++i) {
      if ((1 << i) & k) {
        node = up[node][i];
      }
    }
    return node;
  }
};

// https://www.youtube.com/watch?v=oib-XsjFa-M