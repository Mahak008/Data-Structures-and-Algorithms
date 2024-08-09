const int mod = 1000000007;
int Maximize(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    long long sum = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += (i * (long long)arr[i]);
    }
        
    return sum % mod;
}

// Input : arr[] = [5, 3, 2, 4, 1]
// Output : 40
// Explanation: If we arrange the array as 1 2 3 4 5 then we can see that the minimum index will multiply with minimum number and maximum index will multiply with maximum number. So, 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 0+2+6+12+20 = 40 mod(109+7) = 40
