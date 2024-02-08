// At most 2 transactions with highest profit. 
vector <int> prices = {3,3,5,0,0,3,1,4};
vector<int> v;
int min_now = prices[0];
int n = prices.size();
for(int i = 1;i < n;i++) {
  if(prices[i+1] < prices[i]) {
    int profit = prices[i] - min_now;
    min_now = prices[i+1];
    v.push_back(profit);
  }
}
sort(v.begin(), v.end());
int s = v.size();
int ans;
if(v.empty()) {
  ans = 0;
}
else {
  ans = v[s-1] + v[s-2];
}
cout << ans;

// Input : 1,2,3,4,5
// Output : 4
