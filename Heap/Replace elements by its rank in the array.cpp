vector<int> replaceWithRank(vector<int> &arr, int N){
    set<int> s(arr.begin(), arr.end());
    
    map<int, int> mp;
    int rank = 1;
    
    for(int num : s) {
        mp[num] = rank++; 
    }
    
    vector<int>ans;
    for(int it : arr) {
        ans.push_back(mp[it]);
    }
    
    return ans;
}

// Input:
// N = 6
// arr = [20, 15, 26, 2, 98, 6]
// Output:
// 4, 3, 5, 1, 6, 2
