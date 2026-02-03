// SUBSET SUM
/*
Problema: Descobrir se existe um subconjunto de um conjunto de inteiros que some exatamente t

dp[i] -> é possível fazer a soma i?
*/

int t;
vector<int> a;

vector<bool> dp(t+1, false);
dp[0] = true;

for (int x : a) {
    for (int i = t-x; i >= 0; --i) {
        if (dp[i]) dp[i+x] = true;
    }
}

cout << dp[t] << endl;
