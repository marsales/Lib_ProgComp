// EDIT DISTANCE
// Calcula distância entre duas strings
// Operações: insert, delete e replace

// Time:   O(|a| * |b|)
// Memory: O(min(|a|, |b|))

int edit_distance(const string& a, const string& b) {
    if (a.size() < b.size()) return edit_distance(b, a);

    vector<int> dp(b.size() + 1);
    iota(dp.begin(), dp.end(), 0);

    for (int i = 1; i <= (int)a.size(); ++i) {
        int diagonal = dp[0];
        dp[0] = i;

        for (int j = 1; j <= (int)b.size(); ++j) {
            int old = dp[j];

            dp[j] = min({
                dp[j] + 1,                        // remove a[i - 1]
                dp[j - 1] + 1,                    // insere b[j - 1]
                diagonal + (a[i - 1] != b[j - 1]) // substitui ou mantém
            });

            diagonal = old;
        }
    }

    return dp.back();
}
