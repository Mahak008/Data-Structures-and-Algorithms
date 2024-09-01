int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0, maxSum = 0;
    
    while(i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            sum1 += arr1[i++];
        } else if(arr2[j] < arr1[i]) {
            sum2 += arr2[j++];
        } else {
            maxSum += max(sum1, sum2) + arr1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }
    
    while(i < n) {
        sum1 += arr1[i++];
    }
    
    while(j < m) {
        sum2 += arr2[j++];
    }
    
    maxSum += max(sum1, sum2);
    
    return maxSum;
}

// Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
// Output: 35
// Explanation: The path will be 1+5+7+10+12 = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
