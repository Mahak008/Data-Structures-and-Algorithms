// 2582. Pass the Pillow

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

// Optimised Approach
int passThePillow(int n, int time) {
    int div = time / (n - 1); // calculates the number of complete cycles the pillow has made around the circle.
    int rem = time % (n - 1); // calculates the remaining time after completing the full cycles. 

    return div % 2 == 0 ? rem + 1 : n - rem;
}

// The return value depends on whether the number of complete cycles (div) is even or odd:
// If div is even (div % 2 == 0), the pillow is moving in the initial direction, so the position of the pillow is rem + 1 (since positions are 1-indexed).
// If div is odd, the pillow is moving in the reverse direction, so the position is n - rem.


// Input: n = 4, time = 5
// Output: 2
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
// After five seconds, the 2nd person is holding the pillow.
