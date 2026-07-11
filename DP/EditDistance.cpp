// EDIT DISTANCE/STRING ALIGNMENT/LCS

// Edit Distance: menor distância de edição         -> match = 0 | mismatch = insert = remove = 1
// String Alignment: maior pontuação de alinhamento -> match = 2 | mismatch = insert = remove = -1
// LCS: longest common subsequence                  -> match = 1 | insert = remove = 0 | mismatch = -INF

// Operações: insert, delete e replace (mismatch)

// Time:   O(|a| * |b|)
// Memory: O(min(|a|, |b|))

struct AlignmentScores {
    int match;
    int mismatch;
    int insert;
    int remove;
};

int string_alignment(
    const string& a,
    const string& b,
    const AlignmentScores& score
) {
    int n = (int)a.size();
    int m = (int)b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Alinhar os primeiros i caracteres de a com a string vazia:
    // é necessário remover todos eles.
    for (int i = 1; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] + score.remove;

    // Alinhar a string vazia com os primeiros j caracteres de b:
    // é necessário inserir todos eles.
    for (int j = 1; j <= m; ++j)
        dp[0][j] = dp[0][j - 1] + score.insert;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int diagonal =
                dp[i - 1][j - 1] +
                (a[i - 1] == b[j - 1]
                    ? score.match
                    : score.mismatch);

            int remove_from_a =
                dp[i - 1][j] + score.remove;

            int insert_in_a =
                dp[i][j - 1] + score.insert;

            dp[i][j] = max({
                diagonal,
                remove_from_a,
                insert_in_a
            });
        }
    }

    return dp[n][m];
}
