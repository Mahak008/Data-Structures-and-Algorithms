// Leetcode - 4

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> temp;
    for (int i = 0; i < nums1.size(); i++) {
        temp.push_back(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++) {
        temp.push_back(nums2[i]);
    }

    sort(temp.begin(), temp.end());

    int n = temp.size();
    if (n % 2 == 0) {
        // If the size is even, return the average of the two middle elements
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    } else {
        // If the size is odd, return the middle element
        return temp[n / 2];
    }
}
