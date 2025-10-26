// bfs.hpp
#pragma once
#include <vector>
#include <queue>
#include <utility>

constexpr int UNVISITED = -1;
constexpr int VISITED   =  1;
constexpr int INF       = 1000000000;
using vi   = std::vector<int>;
using vvi  = std::vector<vi>;
using ii   = std::pair<int,int>;
using vii  = std::vector<ii>;
using vvii = std::vector<vii>;

/* ---------------- DFS em LISTA (não ponderado) ---------------- */
inline void dfs_list(int u, const vvi& AdjList, vi& dfs_num) {
    dfs_num[u] = VISITED;
    for (int v : AdjList[u]) {
        if (dfs_num[v] == UNVISITED)
            dfs_list(v, AdjList, dfs_num);
    }
}

/* -------- DFS em LISTA (ponderado) — ignora os pesos --------- */
inline void dfs_list(int u, const vvii& AdjList, vi& dfs_num) {
    dfs_num[u] = VISITED;
    for (const ii& e : AdjList[u]) { // e.first = vizinho, e.second = peso
        int v = e.first;
        if (dfs_num[v] == UNVISITED)
            dfs_list(v, AdjList, dfs_num);
    }
}

/* ---------------- DFS em MATRIZ de adjacência ---------------- */
inline void dfs_matrix(int u, const vvi& AdjMat, vi& dfs_num) {
    int n = (int)AdjMat.size();
    dfs_num[u] = VISITED;
    for (int v = 0; v < n; ++v) {
        if (AdjMat[u][v] && dfs_num[v] == UNVISITED)
            dfs_matrix(v, AdjMat, dfs_num);
    }
}

/* ------------ BFS (apenas visitar) em LISTA não ponderada ------------ */
inline void bfs_list(int s, const vvi& AdjList, vi& state) {
    std::queue<int> q;
    state[s] = VISITED;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : AdjList[u]) {
            if (state[v] == UNVISITED) {
                state[v] = VISITED;
                q.push(v);
            }
        }
    }
}

/* ------------- BFS (apenas visitar) em LISTA ponderada --------------- */
/* (ignora pesos; usa e.first como vizinho) */
inline void bfs_list(int s, const vvii& AdjList, vi& state) {
    std::queue<int> q;
    state[s] = VISITED;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const ii& e : AdjList[u]) {
            int v = e.first;
            if (state[v] == UNVISITED) {
                state[v] = VISITED;
                q.push(v);
            }
        }
    }
}

/* ------------------- BFS (apenas visitar) em MATRIZ ------------------- */
inline void bfs_matrix(int s, const vvi& AdjMat, vi& state) {
    std::queue<int> q;
    int n = (int)AdjMat.size();
    state[s] = VISITED;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; ++v) {
            if (AdjMat[u][v] && state[v] == UNVISITED) {
                state[v] = VISITED;
                q.push(v);
            }
        }
    }
}

/* --------- BFS com distâncias (e pai opcional) – LISTA ---------------- */
inline void bfs_list_dist(int s, const vvi& AdjList, vi& dist, vi* parent = nullptr) {
    int n = (int)AdjList.size();
    dist.assign(n, INF);
    if (parent) parent->assign(n, -1);
    std::queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : AdjList[u]) if (dist[v] == INF) {
            dist[v] = dist[u] + 1;
            if (parent) (*parent)[v] = u;
            q.push(v);
        }
    }
}

/* --------- BFS com distâncias (e pai opcional) – MATRIZ --------------- */
inline void bfs_matrix_dist(int s, const vvi& AdjMat, vi& dist, vi* parent = nullptr) {
    int n = (int)AdjMat.size();
    dist.assign(n, INF);
    if (parent) parent->assign(n, -1);
    std::queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; ++v) if (AdjMat[u][v] && dist[v] == INF) {
            dist[v] = dist[u] + 1;
            if (parent) (*parent)[v] = u;
            q.push(v);
        }
    }
}
