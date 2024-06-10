
long long sumSubarrayMins(vector<int>& arr) {
    long long n = arr.size();
    long long left[n], right[n];

    stack<pair<long long, long long>> s1, s2;

    // getting number of element strictly larger than A[i] on Left.
    for (int i = 0; i < n; ++i) {
        int cnt = 1;

        // get elements from stack until element greater than A[i] found
        while (!s1.empty() && (s1.top().first) > arr[i]) {
            cnt += s1.top().second;
            s1.pop();
        }

        s1.push({arr[i], cnt});
        left[i] = cnt;
    }

    // getting number of element larger than A[i] on Right.
    for (int i = n - 1; i >= 0; --i) {
        long long cnt = 1;

        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) >= arr[i]) {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({arr[i], cnt});
        right[i] = cnt;
    }

    long long result = 0;

    // calculating required resultult
    for (int i = 0; i < n; ++i)
        result = (result + arr[i] * left[i] * right[i]);

    return result;
}

long long sumSubarrayMax(vector<int>& arr) {
    long long n = arr.size();
    long long left[n], right[n];

    stack<pair<long long, long long>> s1, s2;

      // getting number of element strictly smaller than A[i] on Left.
    for (int i = 0; i < n; ++i) {
        long long cnt = 1;

        // get elements from stack until element
        // greater than A[i] found
        while (!s1.empty() && (s1.top().first) < arr[i]) {
            cnt += s1.top().second;
            s1.pop();
        }

        s1.push({arr[i], cnt});
        left[i] = cnt;
    }

    // getting number of element smaller than A[i] on Right.
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 1;

        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) <= arr[i]) {
            cnt += s2.top().second;
            s2.pop();
        }

        s2.push({arr[i], cnt});
        right[i] = cnt;
    }

    long long result = 0;

    // calculating required result
    for (int i = 0; i < n; ++i)
        result = (result + arr[i] * left[i] * right[i]);

    return result;
}
long long subArrayRanges(vector<int>& nums) {
    long long ans;
    long long x = sumSubarrayMins(nums);
    long long y = sumSubarrayMax(nums);
    ans = y - x;
    return ans;
}

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
