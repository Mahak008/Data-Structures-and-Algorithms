// Leetcode - 881
int numRescueBoats(vector<int>& people, int limit) {
  sort(people.begin(), people.end());
  int n = people.size();
  int boats = 0, left = 0, right = n-1;

  while(left <= right) {
    if(people[left] + people[right] <= limit) {
      left++;
    }
    right--;
    boats++;
  }

  return boats;
}

// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)
