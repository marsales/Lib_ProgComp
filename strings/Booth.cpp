// Algoritmo de Booth
// Lexicographically minimal string rotation

string s;
int sz = s.size();  // just a shorthand
int ans = 0;

// Double the string to make it circular and avoid working with modulo
s += s;
HashedString pref(s);
for (int i = 0; i < sz; i++) {
    // Binary search for the first different character
    int lo = 0;
    int hi = sz - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // Check if prefixes match
        if (pref.get_hash(i, i + mid) == pref.get_hash(ans, ans + mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
      }

  // Update answer
  if (s[i + lo] < s[ans + lo]) { ans = i; }
}

cout << s.substr(ans, sz) << endl;
