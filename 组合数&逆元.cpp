#define inf 0x7FFFFFFF
#define mod 123456
#define maxn 123456

using namespace std;


long long fac[maxn], inv[maxn], facinv[maxn];
void init() {
	fac[0] = inv[0] = facinv[0] = 1;
	fac[1] = inv[1] = facinv[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - (mod / i * inv[mod%i] % mod);
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

long long c(int n, int k) {
	if (k > n) return 0;
	return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}