// Only if the element is in consecutive range and repeats twice

vector <int> v1{1, 2, 3, 4, 4};
int ans = 0;

for(unsigned i = 0; i < v1.size(); i++) {
    ans ^= v1[i];
}

for(unsigned i = 1; i < v1.size(); i++) {
    ans ^= i;
}
cout << ans;

// Output - 4
