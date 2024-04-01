#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(vector<long long> &A, long long int N, long long int K) {
    vector<long long> ans;
    queue<long long> q;
    int i = 0, j = 0;

    while (j < K) {
        if (A[j] < 0) {
            q.push(A[j]);
        }
        j++;
    }
    while (j < N) {
        if (!q.empty()) {
            ans.push_back(q.front());
        } else {
            ans.push_back(0);
        }

        if (A[i] < 0) {
            q.pop();
        }

        if (A[j] < 0) {
            q.push(A[j]);
        }
        i++;
        j++;
    }
    if (!q.empty()) {
        ans.push_back(q.front());
    } else {
        ans.push_back(0);
    }
    return ans;
}

int main() {
    vector<long long> v = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = 8, K = 3;
    vector<long long> result = printFirstNegativeInteger(v, N, K);
    
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Output - {-1 -1 -7 -15 -15 0 }

