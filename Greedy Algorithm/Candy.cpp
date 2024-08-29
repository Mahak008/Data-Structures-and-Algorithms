// Leetcode - 135

int candy(vector<int>& ratings) {
    int n = ratings.size();

    if (n == 0) {
        return 0;
    }

    vector<int> right(n, 1), left(n, 1);

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max(left[i], right[i]);
    }

    return sum;
}

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
