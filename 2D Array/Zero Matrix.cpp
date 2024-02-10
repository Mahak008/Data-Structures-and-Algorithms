#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	vector <int> row(n,0), col(m,0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			} 
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}

// Input :
// 2 4 3
// 1 0 0

// Output :
// 2 0 0 
// 0 0 0 
