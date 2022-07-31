const int MOD = 1e9 + 7;
long long mod_pow(long long x, long long n) {
    if (n == 0) return 1;
    long long res = mod_pow(x * x % MOD, n / 2);
    if (n & 1) res = res * x % MOD;
    return res;
}

long long comb(long long n, long long x) {
    long long ret = 1, k = 1;
    for (int i = 0; i < x; i++) ret = (ret * (n - i)) % MOD;
    for (int i = 0; i < x; i++) k = (k * (x - i)) % MOD;
    k = mod_pow(k, MOD - 2);
    ret = (ret * k + MOD) % MOD;
    return ret;
}