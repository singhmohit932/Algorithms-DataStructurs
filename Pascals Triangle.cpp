//Pascals Triangle 
// By using the recurrence relation we can construct a table of binomial coefficients (Pascal's triangle) and 
// take the result from it. The advantage of this method is that intermediate results never exceed the answer and 
// calculating each new table element requires only one addition. The flaw is slow execution for large n and k if 
// you just need a single value and not the whole table (because in order to calculate (nk) you will need to build 
// a table of all (ij),1≤i≤n,1≤j≤n, or at least to 1≤j≤min(i,2k)).The time complexity can be considered to be O(n2). 
// C++ implementation:


const int maxn = ...;
int C[maxn + 1][maxn + 1];
C[0][0] = 1;
for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
}

//If the entire table of values is not necessary, storing only two last rows of it is sufficient 
// (current n-th row and the previous n−1-th).