long long pw(long long x,long long n) {
	if (n == 0) return 1;
	long long res = pw(x*x, n / 2);
	if (n & 1) res = res * x;
	return res;
}
