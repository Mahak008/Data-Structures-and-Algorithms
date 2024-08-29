// Leetcode - 1578

int minCost(string colors, vector<int>& neededTime) {
  int len = colors.length();
  int time = 0;

  for(int i = 1; i < len; i++) {
    if(colors[i] == colors[i-1]) {
      time += min(neededTime[i], neededTime[i-1]);
      neededTime[i] = std::max(neededTime[i], neededTime[i - 1]);
    }
    c = colors[i];
  }

  return time;
}

// Input: colors = "aabaa", neededTime = [1,2,3,4,1]
// Output: 2
