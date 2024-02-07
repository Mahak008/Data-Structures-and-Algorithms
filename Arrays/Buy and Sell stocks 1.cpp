int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int ans = 0;
    int n = prices.size();
    int aux[n];
    aux[n-1] = prices[n-1];
    for(int i = n-2; i >= 0; i--) {
        aux[i] = max(prices[i], aux[i+1]);
    }
    for(int i = 0 ; i < n; i++) {
        aux[i] -= prices[i];
    }
    for(int i = 0; i < n; i++) {
        if(aux[i] > ans) {
            ans = aux[i];
        }
    }
    return ans;
}

// More Optimal Approach

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int ans = 0;
    int min_so_far = INT_MAX;
    for(int i = 0; i < prices.size(); i++) {
        min_so_far = min(min_so_far, prices[i]);
        if(ans < (prices[i] - min_so_far)) {
            ans = prices[i] - min_so_far;
        }
    }
    return ans;
}


// Input : 7, 1, 5, 4, 3, 6
// Output : 5
