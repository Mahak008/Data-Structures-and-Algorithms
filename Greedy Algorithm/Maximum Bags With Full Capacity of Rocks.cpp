// Leetcode - 2279

int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
    int n = rocks.size();
    int ans = 0;
    vector<int> remCapacity;

    for (int i = 0; i < n; i++) {
        int remCap = capacity[i] - rocks[i];
        if (remCap > 0) {
            remCapacity.push_back(remCap);
        }
        if (remCap == 0) {
            ans++;
        }
    }

    sort(remCapacity.begin(), remCapacity.end());

    for (int cap : remCapacity) {
        if (ar >= cap) {
            ar -= cap;
            ans++;
        } else {
            break;
        }
    }

    return ans;
}

// Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
// Output: 3
  
// Explanation:
// Place 1 rock in bag 0 and 1 rock in bag 1.
// The number of rocks in each bag are now [2,3,4,4].
// Bags 0, 1, and 2 have full capacity.
// There are 3 bags at full capacity, so we return 3.
