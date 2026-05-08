// ============================ CRIVO LINEAR ============================
// Fatorar um número em O(n)
struct LinearSieve {
    int n;
    vector<int> lp;        // lowest prime factor
    vector<int> primes;

    LinearSieve(int N) : n(N) {
        lp.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            // i é primo
            if (lp[i] == 0) {
                lp[i] = i;
                primes.push_back(i);
            }

            for (int p : primes) {
                if (1LL * p * i > n) break;
                lp[p * i] = p;
                if (p == lp[i]) break;
            }
        }
    }

    bool isPrime(int x) {
        return x >= 2 && lp[x] == x;
    }

    vector<ii> factorize(int x) {
        vector<ii> factors;

        while (x > 1) {
            int p = lp[x];
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            factors.push_back({p, cnt});
        }

        return factors;
    }
};
