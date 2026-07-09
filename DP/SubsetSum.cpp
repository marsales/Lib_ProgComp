// SUBSET SUM
// Descobrir se existe um subconjunto de um conjunto de inteiros que some exatamente t
// Cada elemento pode ser usado no máximo uma vez
// dp[i] -> é possível fazer a soma i?

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



// SUBSET SUM COM BITSET
// Descobrir se existe um subconjunto que some exatamente t
// Cada elemento pode ser usado no máximo uma vez
// possible[i] = 1 se é possível formar soma i
// Complexidade prática: O(n * MAXS / 64)

const int MAXS = 200000; // ajuste conforme o limite do problema

int t;
vector<int> a;

bitset<MAXS + 1> possible;
possible[0] = 1;

for (int x : a) {
    possible |= (possible << x);
}

cout << possible[t] << endl;
