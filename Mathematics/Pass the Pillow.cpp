int passThePillow(int n, int time) {
    int pos = 1;

    while (time > 0) {
        while (time > 0 && pos < n) {
            pos++;
            time--;
        }
        while (time > 0 && pos > 1) {
            pos--;
            time--;
        }
    }
    return pos;
}

// Input: n = 4, time = 5
// Output: 2
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
// After five seconds, the 2nd person is holding the pillow.
