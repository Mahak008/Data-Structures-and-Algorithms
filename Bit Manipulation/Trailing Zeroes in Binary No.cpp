int A = 18, count = 0;
while((A & 1) == 0) {
    count++;
    A = A >> 1;
}
cout << count;

// Output - 1
// 18 in binary is represented as: 10010, there is 1 trailing zero.
// 8 in binary is represented as: 1000, there are 3 trailing zeroes.
