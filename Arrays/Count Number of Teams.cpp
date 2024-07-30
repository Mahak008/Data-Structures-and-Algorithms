// Leetcode - 1395

int numTeams(vector<int>& rating) {
    int n = rating.size();
    int teams = 0;

    for (int j = 1; j < n - 1; j++) {
        int countSmallerLeft = 0;
        int countLargerLeft = 0;
        int countSmallerRight = 0;
        int countLargerRight = 0;

        for (int i = 0; i < j; i++) {
            if (rating[i] < rating[j]) {
                countSmallerLeft++;
            } else if (rating[i] > rating[j]) {
                countLargerLeft++;
            }
        }

        for (int k = j + 1; k < n; k++) {
            if (rating[k] < rating[j]) {
                countSmallerRight++;
            } else if (rating[k] > rating[j]) {
                countLargerRight++;
            }
        }

        teams += (countLargerLeft * countSmallerRight +
                  countSmallerLeft * countLargerRight);
    }

    return teams;
}

// Input: rating = [2,5,3,4,1]
// Output: 3
// Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
