// Grafo ponderado:
// adj[u] = lista de {v, peso}
vector<ll> dijkstra(int source, const vector<vector<pair<int, ll>>>& adj) {
    int n = adj.size();

    vector<ll> dist(n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
