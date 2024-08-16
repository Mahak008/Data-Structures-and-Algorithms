// Leetcode - 624

int maxDistance(vector<vector<int>>& arrays) {
    int n = arrays.size();
    int min_num = arrays[0].front();
    int max_num = arrays[0].back();
    int max_dis = INT_MIN;

    for (int i = 1; i < n; i++) {
        max_dis = max({max_dis, abs(arrays[i].back() - min_num),
                       abs(arrays[i].front() - max_num)});
        min_num = min(min_num, arrays[i].front());
        max_num = max(max_num, arrays[i].back());
    }

    return max_dis;
}

// Input: arrays = [[1,2,3],[4,5],[1,2,3]]
// Output: 4
// Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
