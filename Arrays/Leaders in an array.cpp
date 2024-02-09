vector<int> superiorElements(vector<int>&a) {
    vector <int> v;
    int n = a.size();
    v.push_back(a[n-1]);
    for(int i = 0; i < n-1; i++) {
        bool leader = true;
        for(int j = i+1; j < n; j++) {
            if(a[i] <= a[j]) {
                leader = false;
                break;
            }
        }
        if(leader == true) {
            v.push_back(a[i]);
        }
    }
    reverse(v.begin()+1, v.end());
    return v;
}

// Optimal Approach - If an element is greater than the maximum element on its right, it is the leader element.
vector<int> superiorElements(vector<int>&a) {
    vector <int> v;
    int n = a.size();
    v.push_back(a[n-1]);
    int max_now = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        if(a[i] > max_now) {
            v.push_back(a[i]);
        }
        max_now = max(max_now, a[i]);
    }
    return v;
}

// Input : 5 4 3
// Output : 3 4 5 
