bool place(vector<int>& position, int dist, int m) {
    int last = position[0], basket = 1;

    for (int i = 1; i < position.size(); i++) {
        if (position[i] - last >= dist) {
            basket++;
            last = position[i];
        }
    }
    if (basket >= m) {
        return true;
    }
    return false;
}
int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());

    int low = 0, high = position[position.size() - 1] - position[0];

    while (low <= high) {
        int mid = (low + high) / 2;
        bool x = place(position, mid, m);

        if (x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
