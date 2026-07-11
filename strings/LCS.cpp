// LONGEST COMMON SUBSEQUENCE
/*
Problema:
Encontrar o tamanho da maior subsequência comum entre duas strings

dp[i][j] -> tamanho da LCS entre A[0..i] e B[0..j]
*/
string a, b;

int best(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 0;
    if (a[i] = b[j]) {
        dp[i][j] = 1 + best(i-1, j-1);
    } else {
        dp[i][j] = max( best(i-1, j), best(i, j-1) );
    }

    return dp[i][j];
}
// n -> tamanho da string a
// m -> tamanho da string b
vector<vector<int>> dp(n, vector<int>(m, -1));

cout << best(n-1, m-1) << endl;
