vector <int> getFrequencies(vector<int>& v) {
    map <int, int> m;
    for(int i = 0; i < v.size(); i++) {
        m[v[i]]++;
    }
    int maxEle = INT_MIN, minEle = INT_MAX;
    int ans1 = 0, ans2 = 0;
    for(auto i : m) {
        if(i.second > maxEle) {
            ans1 = i.first;
            maxEle = i.second;
        }
        if(i.second < minEle) {
            ans2 = i.first;
            minEle = i.second;
        }
    }
    return {ans1, ans2};
}

// Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]
// Output: 1 2
