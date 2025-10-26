#pragma once
#include <bits/stdc++.h>

// ===================================== DFS / BFS =====================================
inline void dfs_list(int u, const vector<vector<int>>& AdjList, vector<int>& dfs_num ) {
  dfs_num[u] = 1;
  for (int v : AdjList[u]) {
    if (dfs_num[v] == -1) {
      dfs_list(v, AdjList, dfs_num);
    }
  }
}

inline void dfs_matrix(int u, const vector<vector<int>>& AdjMat, vi& dfs_num) {
  int n = (int)AdjMat.size();
  dfs_num[u] = 1;
  for (int v = 0; v < n; ++v) {
    if (AdjMat[u][v] && dfs_num[v] == -1) {
      dfs_matrix(v, AdjMat, dfs_num);
    }
  }
}

inline void bfs_list(int s, const vector<vector<int>>& AdjList, vector<int>& state) {
  std::queue<int> q;
  state[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : AdjList[u]) {
      if (state[v] == -1) {
        state[v] = 1;
        q.push();
      }
    }
  }
}

inline void bfs_matrix(int s, const vector<vector<int>>& AdjMat, vector<int>& state) {
  std::queue<int> q;
  int n = (int)AdjMat.size();
  state[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; ++v) {
      if (AdjMat[u][v] && state[v] == -1) {
        state[v] = 1;
        q.push(v);
      }
    }
  }
}

