#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <numeric>   // for accumulate

int students(const std::vector<int>& arr, int pages) {
    int stu = 1;
    long long pagestu = 0; 
    for(int i = 0; i < arr.size(); i++) {
        if(pagestu + arr[i] <= pages) {
            pagestu += arr[i];
        } else {
            stu += 1;
            pagestu = arr[i];
        }
    }
    return stu;
}

int findPages(std::vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *std::max_element(arr.begin(), arr.end());
    int high = std::accumulate(arr.begin(), arr.end(), 0);
    while(low <= high) {
        int mid = (low + high) / 2;
        int stu = students(arr, mid);
        if(stu > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

