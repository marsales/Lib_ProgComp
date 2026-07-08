// 0-indexed
// adj: árvore não direcionada
// root: raiz escolhida
// parent[u]: pai de u na árvore enraizada
// sz[u]: tamanho da subárvore de u, incluindo o próprio u

void build_rooted_tree(const vector<vi>& adj, int root, vi& parent, vi& sz) {
    int n = adj.size();

    parent.assign(n, -2);
    sz.assign(n, 1);

    vi order;
    order.reserve(n);

    stack<int> st;
    st.push(root);
    parent[root] = -1;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        order.push_back(u);

        for (int v : adj[u]) {
            if (v == parent[u]) continue;
            if (parent[v] != -2) continue; // segurança extra

            parent[v] = u;
            st.push(v);
        }
    }

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];

        for (int v : adj[u]) {
            if (parent[v] == u) {
                sz[u] += sz[v];
            }
        }
    }
}
