// Leetcode - 948

int bagOfTokensScore(vector<int>& tokens, int power) {
  sort(tokens.begin(), tokens.end());
  int n = tokens.size();
  int score = 0, ans = 0, left = 0, right = n-1;

  while(left <= right) {
    if(power >= tokens[left]) {
      power -= tokens[left];
      score++;
      left++;
    } else if(score > 0) {
      power += tokens[right];
      score--;
      right--;
    } else {
      break;
    }

    ans = max(ans, score);
  }

  return ans;
}

// Input: tokens = [100,200,300,400], power = 200
// Output: 2

// Explanation: Play the tokens in this order to get a score of 2:
// Play token0 (100) face-up, reducing power to 100 and increasing score to 1.
// Play token3 (400) face-down, increasing power to 500 and reducing score to 0.
// Play token1 (200) face-up, reducing power to 300 and increasing score to 1.
// Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
// The maximum score achievable is 2.
