using matrix = vector<vector<long long>>;

int MOD = 1e9 + 7; 

matrix mul(matrix& a, matrix& b) {
    int n = a.size(), m = b[0].size();
    matrix c = matrix(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            if (a[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix pow_mul(matrix a, int n, matrix& f1) {
    matrix res = f1;
    for(auto v : res) cout << v[0] << " ";
    cout << endl;
    while (n) {
        if (n & 1) {
            res = mul(a, res);
            for(auto v : res) cout << v[0] << " ";
            cout << endl;
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        
	    matrix fn = pow_mul(mtr, n - 2, f1);

        return fn[0][0] << 1;
        
    }
};
