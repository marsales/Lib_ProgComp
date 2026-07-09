// KNAPSACK
// Dada uma mochila com capacidade W 
// e n itens, cada um com peso w[i] e valor v[i]
// Qual o maior valor que dá pra colocar na mochila sem passar do peso?

// dp[w] -> melhor valor com capacidade w
int n, W;
vector<int> w, v;

vector<int> dp(W+1, 0);

for (int i = 0; i < n; ++i) {
    for (int k = W - w[i]; k >= 0; --k) {
        dp[k + w[i]] = max( dp[k + w[i]] , dp[k] + v[i] );
    }
}

cout << dp[W] << endl;

// UNBOUNDED KNAPSACK
// Cada item pode ser usado quantas vezes quiser
// Complexidade: O(nW)

long long unbounded_knapsack(const vector<int>& weight, const vector<int>& value, int W) {
    int n = weight.size();

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int cap = weight[i]; cap <= W; cap++) {
            dp[cap] = max(dp[cap], dp[cap - weight[i]] + value[i]);
        }
    }

    return dp[W];
}

// 0/1 EXACT KNAPSACK
// Retorna maior valor para peso exatamente W
// Se for impossível, retorna -1
// Complexidade: O(nW)

long long knapsack01_exact(const vector<int>& weight, const vector<int>& value, int W) {
    const long long NEG = -4e18;

    int n = weight.size();

    vector<long long> dp(W + 1, NEG);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int cap = W; cap >= weight[i]; cap--) {
            if (dp[cap - weight[i]] != NEG) {
                dp[cap] = max(dp[cap], dp[cap - weight[i]] + value[i]);
            }
        }
    }

    return dp[W] == NEG ? -1 : dp[W];
}
