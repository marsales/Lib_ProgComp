// KMP - KNUTH-MORRIS-PRATT

// failure[i] = length of the longest proper prefix of pattern[0..i]
//              that is also a suffix
vector<int> kmpPreprocess(const string& pattern) {
    int m = (int)pattern.size();

    vector<int> failure(m);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = failure[j - 1];

        if (pattern[i] == pattern[j])
            j++;

        failure[i] = j;
    }

    return failure;
}

// Returns every occurrence, including overlapping ones
// Time: O(|text| + |pattern|)
// Memory: O(|pattern|)
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> occurrences;

    if (pattern.empty())
        return occurrences;

    vector<int> failure = kmpPreprocess(pattern);
    int j = 0;

    for (int i = 0; i < (int)text.size(); i++) {
        while (j > 0 && text[i] != pattern[j])
            j = failure[j - 1];

        if (text[i] == pattern[j])
            j++;

        if (j == (int)pattern.size()) {
            occurrences.push_back(i - (int)pattern.size() + 1);
            j = failure[j - 1];
        }
    }

    return occurrences;
}

// Returns the first occurrence, or -1 if it does not exist.
// Time: O(|text| + |pattern|)
int kmpFind(const string& text, const string& pattern) {
    if (pattern.empty())
        return 0;

    vector<int> failure = kmpPreprocess(pattern);
    int j = 0;

    for (int i = 0; i < (int)text.size(); i++) {
        while (j > 0 && text[i] != pattern[j])
            j = failure[j - 1];

        if (text[i] == pattern[j])
            j++;

        if (j == (int)pattern.size())
            return i - (int)pattern.size() + 1;
    }

    return -1;
}
