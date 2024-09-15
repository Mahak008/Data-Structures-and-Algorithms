// Leetcode - 1310

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> pre(n);
    pre[0] = arr[0];

    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] ^ arr[i];
    }

    vector<int> res(queries.size());

    for (int i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];

        if (a == 0) {
            res[i] = pre[b];
        } else {
            res[i] = pre[b] ^ pre[a - 1];
        }
    }

    return res;
}

// Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
// Output: [2,7,14,8] 

// Explanation: 
// The binary representation of the elements in the array are:
// 1 = 0001 
// 3 = 0011 
// 4 = 0100 
// 8 = 1000 
// The XOR values for queries are:
// [0,1] = 1 xor 3 = 2 
// [1,2] = 3 xor 4 = 7 
// [0,3] = 1 xor 3 xor 4 xor 8 = 14 
// [3,3] = 8  
