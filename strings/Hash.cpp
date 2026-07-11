// DOUBLE ROLLING HASH
// Comparar strings em O(1)

struct Hash {
    ll h1, h2;

    bool operator==(const Hash& other) const {
        return h1 == other.h1 && h2 == other.h2;
    }

    bool operator!=(const Hash& other) const {
        return !(*this == other);
    }
};

struct Hasher {
    static const ll P1 = 31;
    static const ll P2 = 37;
    static const ll M1 = 1e9+33;
    static const ll M2 = 1e9+93;

    int n;

    vll prefix_hash1, prefix_hash2;
    vll powers1, powers2;

    Hasher() {}

    Hasher(const string& s) {
        build(s);
    }

    void build(const string& s) {
        n = (int)s.size();

        prefix_hash1.assign(n + 1, 0);
        prefix_hash2.assign(n + 1, 0);

        powers1.assign(n + 1, 1);
        powers2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            powers1[i] = powers1[i - 1] * P1 % M1;
            powers2[i] = powers2[i - 1] * P2 % M2;
        }

        for (int i = 0; i < n; i++) {
            ll val = (unsigned char)s[i];

            prefix_hash1[i + 1] =
                (prefix_hash1[i] * P1 + val) % M1;

            prefix_hash2[i + 1] =
                (prefix_hash2[i] * P2 + val) % M2;
        }
    }

    // Hash da substring s[l ... r].
    // Intervalo inclusivo: [l, r]
    // Time: O(1)
    Hash substr_hash(int l, int r) const {
        int len = r - l + 1;

        ll h1 =
            (prefix_hash1[r + 1] -
             prefix_hash1[l] * powers1[len] % M1 +
             M1) % M1;

        ll h2 =
            (prefix_hash2[r + 1] -
             prefix_hash2[l] * powers2[len] % M2 +
             M2) % M2;

        return {h1, h2};
    }

    // Compara s[l1 ... r1] com s[l2 ... r2].
    bool equal(int l1, int r1, int l2, int r2) const {
        if (r1 - l1 != r2 - l2)
            return false;

        return substr_hash(l1, r1) ==
               substr_hash(l2, r2);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abracadabra";

    Hasher h(s);

    // "abra"
    Hash x = h.substr_hash(0, 3);

    // "abra"
    Hash y = h.substr_hash(7, 10);

    if (x == y)
        cout << "iguais\n";

    return 0;
}
