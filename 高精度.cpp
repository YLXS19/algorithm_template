#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<algorithm> 
#include<string.h>
#include<iostream>
#include<queue>
#include<math.h>
#include<string>
#include<map>
#include<functional>
#include<unordered_map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_set>
using namespace std;


const int N = 524288, P = 998244353, inv2 = P + 1 >> 1;
typedef std::vector<int> VI;
int fix(int x) { return (x >> 31 & P) + x; }



int InvL, L, R[N], w[N];
int Pow(int x, int k) {
	int r = 1;
	for (; k; k >>= 1, x = 1LL * x * x % P)
	if (k & 1)
		r = 1LL * r * x % P;
	return r;
}
int Inv(int x) { return Pow(x, P - 2); }
void Pre(int m) {
	int x = 0; L = 1;
	for (; (L <<= 1) < m; ++x);
	for (int i = 1; i < L; ++i)
		R[i] = R[i >> 1] >> 1 | (i & 1) << x;
	int wn = Pow(3, (P - 1) / L); w[0] = 1;
	for (int i = 1; i < L; ++i)
		w[i] = 1LL * w[i - 1] * wn % P;
	InvL = Inv(L);
}
void NTT(int *F) {
	for (int i = 0; i < L; ++i)
	if (R[i] > i)
		std::swap(F[i], F[R[i]]);
	for (int i = 1, d = L >> 1; i < L; i <<= 1, d >>= 1)
	for (int j = 0; j < L; j += i << 1) {
		int *l = F + j, *r = F + i + j, *p = w, tp;
		for (int k = i; k--; ++l, ++r, p += d)
			tp = 1LL * *p * *r % P, *r = (*l - tp) % P, *l = (*l + tp) % P;
	}
}
void Fill(const VI &a, int *A, int m) {
	m = std::min(m, (int)a.size());
	for (int i = 0; i < m; ++i)
		A[i] = a[i];
	for (int i = m; i < L; ++i)
		A[i] = 0;
}
void Fill(int *A, int *B, int m) {
	for (int i = 0; i < m; ++i)
		B[i] = A[i];
	for (int i = m; i < L; ++i)
		B[i] = 0;
}
VI operator * (const VI &a, const VI &b) {
	const int Lim = 3000;
	int asz = a.size(), bsz = b.size(), m = asz + bsz - 1;
	static VI c; c.resize(m);
	if (1LL * asz * bsz <= Lim) {
		for (int i = 0; i < m; ++i)
			c[i] = 0;
		for (int i = 0; i < asz; ++i)
		for (int j = 0; j < bsz; ++j)
			c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;
		return c;
	}
	Pre(m); static int A[N], B[N];
	Fill(a, A, asz); Fill(b, B, bsz);
	NTT(A); NTT(B);
	for (int i = 0; i < L; ++i)
		A[i] = (1LL * A[i] * B[i]) % P;
	NTT(A);
	for (int i = 0; i < m; ++i)
		c[i] = fix(1LL * A[L - i & L - 1] * InvL % P);
	return c;
}
VI operator - (const VI &a, const VI &b) {
	int n = std::max(a.size(), b.size());
	static VI c; c.resize(n, 0);
	for (int i = 0; i < a.size(); ++i)
		c[i] = a[i];
	for (int i = 0; i < b.size(); ++i)
		c[i] = fix(c[i] - b[i]);
	return c;
}
VI operator + (const VI &a, const VI &b) {
	int n = std::max(a.size(), b.size());
	static VI c; c.resize(n, 0);
	for (int i = 0; i < a.size(); ++i)
		c[i] = a[i];
	for (int i = 0; i < b.size(); ++i)
		c[i] = (c[i] + b[i]) % P;
	return c;
}
VI Inv(const VI &a, const int m) { //多项式求逆
	static int A[N], B[N], C[N];
	for (int i = 0; i < m; ++i)
		A[i] = 0;
	A[0] = Inv(a[0]);
	int n = 1;
	for (; n < m;) {
		Pre(n << 2);
		Fill(a, B, n << 1);
		Fill(A, C, n);
		NTT(B); NTT(C);
		for (int i = 0; i < L; ++i)
			B[i] = 1LL * B[i] * C[i] % P * C[i] % P;
		NTT(B);
		n <<= 1;
		for (int i = 0; i < n; ++i)
			A[i] = ((A[i] << 1) - 1LL * B[L - i & L - 1] * InvL) % P;
	}
	static VI c; c.resize(m);
	for (int i = 0; i < m; ++i)
		c[i] = fix(A[i]);
	return c;
}
VI deri(const VI &a) { //多项式求导 
	static VI c;
	if (a.size() == 1) return VI(1, 0);
	c.resize(a.size() - 1);
	for (int i = 0; i < a.size() - 1; ++i)
		c[i] = 1LL * a[i + 1] * (i + 1) % P;
	return c;
}
VI inter(const VI &a) { //多项式积分 
	static VI c; c.resize(a.size() + 1);
	c[0] = 0;
	for (int i = 0; i < a.size(); ++i)
		c[i + 1] = 1LL * a[i] * Inv(i + 1) % P;
	return c;
}
VI Ln(const VI &a, const int m) { //多项式求Ln 
	static VI c;
	c = deri(a) * Inv(a, m - 1);
	c.resize(m - 1);
	return inter(c);
}
VI Sqrt(const VI &a) { //多项式开根 
	static VI b, c;
	b.resize(1);
	b[0] = 1; //仅仅在a0=1的时候成立，否则的话要用BSGS 
	int n = 1, m = a.size();
	for (; n < m;) {
		n <<= 1;
		c = Inv(b, n);
		b = b * b; b.resize(n);
		for (int i = 0; i < std::min(n, m); ++i)
			b[i] = 1LL * (b[i] + a[i]) * inv2 % P;
		b = b * c;
		b.resize(n);
	}
	b.resize(m);
	return b;
}
VI Exp(const VI &a, const int m) { //多项式求exp 
	static VI f, g; f.resize(1); f[0] = 1;
	int n = 1, sz = a.size();
	for (; n < m;) {
		n <<= 1; g = Ln(f, n);
		for (int i = 0; i < n; ++i)
			g[i] = i < sz ? fix(a[i] - g[i]) : fix(-g[i]);
		(++g[0]) %= P;
		f = f * g; f.resize(n);
	}
	f.resize(m);
	return f;
}
VI Pow(const VI &a, int k, int n) { //多项式快速幂 
	static VI f; f = Ln(a, n);
	for (int i = 0; i < n; ++i)
		f[i] = 1LL * f[i] * k % P;
	return Exp(f, n);
}
VI operator / (const VI &a, const VI &b) { //多项式除法
	static VI f, g, q; f = a; g = b;
	std::reverse(f.begin(), f.end());
	std::reverse(g.begin(), g.end());
	int n = f.size(), m = g.size();
	q = Inv(g, n - m + 1); f.resize(n - m + 1);
	q = q * f; q.resize(n - m + 1);
	std::reverse(q.begin(), q.end());
	return q;
}
VI operator % (const VI &a, const VI &b) { //多项式取余
	if (a.size() < b.size()) return a;
	static VI c; c = a - (a / b) * b;
	c.resize(b.size() - 1);
	return c;
}
int Push(const VI &f, const VI &a, int n) { //线性递推 
	static VI mod, r, b; mod = f;
	std::reverse(mod.begin(), mod.end());
	for (int i = 0; i < mod.size(); ++i)
		mod[i] *= -1;
	mod.push_back(1);
	r.resize(1, 1); b.resize(2, 0); b[1] = 1;
	for (; n; b = b * b % mod, n >>= 1)
	if (n & 1)
		r = r * b % mod;
	long long ans = 0;
	for (int i = 0; i < a.size(); ++i)
		ans += 1LL * r[i] * a[i] % P;
	return fix(ans % P);
}
namespace Value { //多项式多点求值 
	VI res, p[N];
	void Pre(int i, int L, int R, const VI &a) {
		if (L == R) {
			p[i].resize(2);
			p[i][0] = fix(-a[L]);
			p[i][1] = 1;
			return;
		}
		int m = L + R >> 1;
		Pre(i << 1, L, m, a); Pre(i << 1 | 1, m + 1, R, a);
		p[i] = p[i << 1] * p[i << 1 | 1];
	}
	void Solve(int i, int L, int R, VI f, const VI &a) {
		if (L == R)
			return res[L] = f[0], void();
		int m = L + R >> 1;
		Solve(i << 1, L, m, f % p[i << 1], a);
		Solve(i << 1 | 1, m + 1, R, f % p[i << 1 | 1], a);
	}
	VI Query(const VI &f, const VI &a) {
		int m = a.size(); res.resize(m);
		Pre(1, 0, m - 1, a);
		Solve(1, 0, m - 1, f % p[1], a);
		return res;
	}
}
namespace Lag { //多项式快速插值
	VI g;
	VI Solve(int i, int L, int R, const VI &y) {
		if (L == R) return VI(1, 1LL * y[L] * g[L] % P);
		int m = L + R >> 1;
		return Solve(i << 1, L, m, y) * Value::p[i << 1 | 1] +
			Value::p[i << 1] * Solve(i << 1 | 1, m + 1, R, y);
	}
	VI Calc(const VI &x, const VI &y) {
		int n = x.size();
		Value::Pre(1, 0, n - 1, x);
		g = deri(Value::p[1]);
		Value::res.resize(n);
		Value::Solve(1, 0, n - 1, g, x);
		for (int i = 0; i < n; ++i)
			g[i] = Inv(Value::res[i]);
		return Solve(1, 0, n - 1, y);
	}
}
int main() 
{



	system("pause");
	return 0;
}

