// =========================== EULER TOUR ===========================
// Travessia DFS que atribui a cada nó um tempo de entrada e saída
void eulerTour(int node, int prev) {
    tin[node] = timer++;
    for (int n : adj[node]) {
        if (n != prev) eulerTour(n, node);
    }
    tout[node] = timer;
}

// Checar se u é ancestral de v
bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// Calcular a soma dos nós na subárvore que começa em x
// -> Percorrer o array de euler tour de in[u] até out[u] somando os valores
// Se forem várias queries / for preciso mudar o valor de um nó -> Seg Tree



// =========================== BINARY LIFTING ===========================
// Pré-computa para cada nó seus ancestrais em potências de 2
void dfsBinLift(int v, int p, int d) {
    tin[v] = ++timer;
    depth[v] = d;
    
    // Construção da matriz de binary lifting
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int u : adj[v]) {
        if (u != p) dfsBinLift(u, v, d+1);
    }

    tout[v] = ++timer;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n)); // Altura da árvore
    up.assign(n, vector<int>(l+1)); // Matriz de binary lifting
    dfs(root, root);
}

// Encontrar k-ésimo ancestral de um nó
int kthAncestor(int node, int k) {
    int cur = node;
    for (int i = 0; (1 << i) <= k; i++) {
        if ((1 << i) & k) cur = up[cur][i];
    }
    return cur;
}

// Encontrar k-ésimo sucessor num grafo funcional
int kthSuccessor(int node, ll k) {
    int cur = node;

    for (ll i = 0; (1LL<<i) <= k; i++) {
        if ((1<<i) & k) cur = up[cur][i];
    }
    return cur;
}
l = log2(MAXK) + 5;
up.assign(n, vector<int>(l+1));



// =========================== LOWEST COMMON ANCESTOR (LCA) ===========================
// Encontrar o lca entre dois nós
int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

// Distância entre dois nós
dist = depth[u] + depth[v] - 2 * depth[lca(u,v)];

// Maior valor entre dois nós
maxV(u,v) = max( maxV(u, lca(u,v)), maxV(v, lca(u, v)) );
