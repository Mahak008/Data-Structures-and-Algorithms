vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0, j = 0;

    vector <int> v;
    while(i < a.size()  && j < b.size()) {
        if(a[i] <= b[j]) {
            if(v.size() == 0 || v.back() != a[i]) {
                v.push_back(a[i]);
            }
            i++;
        }
        else {
            if(v.size() == 0 || v.back() != b[j]) {
                v.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < a.size()) {
        if(v.size() == 0 || v.back() != a[i]) {
            v.push_back(a[i]);
        }
        i++;
    }

    while (j < b.size()) {
        if(v.size() == 0 || v.back() != b[j]) {
            v.push_back(b[j]);
        }
        j++;
    }
    return v;
}

// Input: ‘n’ = 5 ‘m’ = 3
// ‘a’ = [1, 2, 3, 4, 6]
// ‘b’ = [2, 3, 5]

// Output: [1, 2, 3, 4, 5, 6]
