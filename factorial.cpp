
//First we precompute all factorials modulo m up to MAXN! in O(MAXN) time.
factorial[0] = 1;
for (int i = 1; i <= MAXN; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
}

//And afterwards we can compute the binomial coefficient in O(logm) time.
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % MOD) % MOD;
}


//We even can compute the binomial coefficient in O(1) time if we precompute the inverses of all factorials 
// in O(MAXNlogm) using the regular method for computing the inverse, or even in O(MAXN) time using the 
// congruence (x!)−1≡((x−1)!)−1⋅x−1 and the method for computing all inverses in O(n).



long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
}


int x, y;
int g = extended_euclidean(a, m, x, y);
if (g != 1) {
    cout << "No solution!";
}
else {
    x = (x % m + m) % m;
    cout << x << endl;
}

/********************************************************/
//log(b) time complexity
long long inv(long long a, long long b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

/*********************************************************/
