double averageWaitingTime(vector<vector<int>>& customers) {
    int n = customers.size();
    double time = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum < customers[i][0]) {
            sum = customers[i][0] + customers[i][1];
        } else {
            sum += customers[i][1];
        }
        time += (sum - customers[i][0]);
    }

    return time / n;
}

// Input: customers = [[5,2],[5,4],[10,3],[20,1]]
// Output: 3.25000
// Explanation:
// 1) The first customer arrives at time 5, the chef takes his order and starts preparing it immediately at time 5, and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
// 2) The second customer arrives at time 5, the chef takes his order and starts preparing it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
// 3) The third customer arrives at time 10, the chef takes his order and starts preparing it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
// 4) The fourth customer arrives at time 20, the chef takes his order and starts preparing it immediately at time 20, and finishes at time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
// So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.
 
