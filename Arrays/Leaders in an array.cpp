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

// Input : 5 4 3
// Output : 3 4 5 
