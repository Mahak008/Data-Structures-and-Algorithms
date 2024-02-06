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

// Input : 7, 1, 5, 4, 3, 6
// Output : 5
