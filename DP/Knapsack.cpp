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



// 0/1 KNAPSACK BY VALUE
// Útil quando W é grande, mas soma dos valores é pequena
// Complexidade: O(n * sumValue)

long long knapsack01_by_value(const vector<int>& weight, const vector<int>& value, int W) {
    const long long INF = 4e18;

    int n = weight.size();

    int sumValue = 0;
    for (int x : value) sumValue += x;

    vector<long long> dp(sumValue + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int val = sumValue; val >= value[i]; val--) {
            dp[val] = min(dp[val], dp[val - value[i]] + weight[i]);
        }
    }

    long long ans = 0;

    for (int val = 0; val <= sumValue; val++) {
        if (dp[val] <= W) {
            ans = val;
        }
    }

    return ans;
}



// BOUNDED KNAPSACK
// Cada item i pode ser usado no máximo cnt[i] vezes
// Usa decomposição binária
// Complexidade: O(W * soma(log cnt[i]))

long long bounded_knapsack(
    const vector<int>& weight,
    const vector<int>& value,
    const vector<int>& cnt,
    int W
) {
    vector<int> newWeight;
    vector<int> newValue;

    int n = weight.size();

    for (int i = 0; i < n; i++) {
        int c = cnt[i];
        int p = 1;

        while (c > 0) {
            int take = min(p, c);

            newWeight.push_back(weight[i] * take);
            newValue.push_back(value[i] * take);

            c -= take;
            p <<= 1;
        }
    }

    return knapsack01(newWeight, newValue, W);
}



// 0/1 KNAPSACK COM RECONSTRUÇÃO
// Retorna {valor máximo, lista de índices escolhidos}
// Complexidade: O(nW)

pair<long long, vector<int>> knapsack01_reconstruct(
    const vector<int>& weight,
    const vector<int>& value,
    int W
) {
    int n = weight.size();

    vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            dp[i][cap] = dp[i - 1][cap];

            if (cap >= weight[i - 1]) {
                dp[i][cap] = max(
                    dp[i][cap],
                    dp[i - 1][cap - weight[i - 1]] + value[i - 1]
                );
            }
        }
    }

    vector<int> chosen;

    int cap = W;

    for (int i = n; i >= 1; i--) {
        if (dp[i][cap] != dp[i - 1][cap]) {
            chosen.push_back(i - 1);
            cap -= weight[i - 1];
        }
    }

    reverse(chosen.begin(), chosen.end());

    return {dp[n][W], chosen};
}



// MULTIPLE CHOICE KNAPSACK
// groups[g] = lista de itens {peso, valor} do grupo g
// Pode escolher no máximo um item de cada grupo
// Complexidade: O(totalItens * W)

long long multiple_choice_knapsack(
    const vector<vector<pair<int,int>>>& groups,
    int W
) {
    vector<long long> dp(W + 1, 0);

    for (const auto& group : groups) {
        vector<long long> ndp = dp;

        for (int cap = 0; cap <= W; cap++) {
            for (auto [weight, value] : group) {
                if (cap >= weight) {
                    ndp[cap] = max(ndp[cap], dp[cap - weight] + value);
                }
            }
        }

        dp = ndp;
    }

    return dp[W];
}



// 0/1 KNAPSACK COM 2 RESTRIÇÕES
// Cada item tem peso, volume e valor
// Complexidade: O(nWV)

long long knapsack01_2d_capacity(
    const vector<int>& weight,
    const vector<int>& volume,
    const vector<int>& value,
    int W,
    int V
) {
    int n = weight.size();

    vector<vector<long long>> dp(W + 1, vector<long long>(V + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int capW = W; capW >= weight[i]; capW--) {
            for (int capV = V; capV >= volume[i]; capV--) {
                dp[capW][capV] = max(
                    dp[capW][capV],
                    dp[capW - weight[i]][capV - volume[i]] + value[i]
                );
            }
        }
    }

    return dp[W][V];
}
