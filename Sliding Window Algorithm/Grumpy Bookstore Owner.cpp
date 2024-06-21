int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int satisfied = 0;
    int n = customers.size();

    for (int i = 0; i < n; i++) {
        if (grumpy[i] == 0) {
            satisfied += customers[i];
        }
    }

    int left = 0, right = 0, max_sat = 0;
    while (right < minutes) {
        if (grumpy[right] == 1) {
            max_sat += customers[right];
        }
        right++;
    }

    int one_sum = max_sat;
    while (right < n) {
        if (grumpy[left] == 1) {
            one_sum -= customers[left];
        }
        if (grumpy[right] == 1) {
            one_sum += customers[right];
        }
        max_sat = max(max_sat, one_sum);
        left++;
        right++;
    }

    satisfied += max_sat;
    return satisfied;
}

// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16
// Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
// The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
