long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long Max = 0;
        long sum = 0;
        int i = 0, j ;
    
        // Calculate sum of first K elements
        for (j = 0; j < K; ++j) {
            sum += Arr[j];
        }
        Max = sum;
    
        // Slide the window and update sum and Max
        while (j < N) {
            sum += Arr[j] - Arr[i];
            Max = max(Max, sum);
            ++i;
            ++j;
        }
        return Max;
