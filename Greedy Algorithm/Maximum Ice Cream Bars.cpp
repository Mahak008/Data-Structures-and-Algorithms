// Leetcode - 1833

int maxIceCream(vector<int>& costs, int coins) {
  sort(costs.begin(), costs.end());
  int x = 0, ans = 0;

  for(int i = 0; i < costs.size(); i++) {
    if(x + costs[i] <= coins) {
      x += costs[i];
      ans++;
    } else {
      break;
    }
  }
  return ans;
}

// Input: costs = [1,3,2,4,1], coins = 7
// Output: 4
// Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
