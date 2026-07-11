long long fexp(long long a, long long e, long long mod) {
    long long r = 1 % mod;
    a %= mod;

    while (e > 0) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }

    return r;
}
