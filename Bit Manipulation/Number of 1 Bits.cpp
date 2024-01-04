int A = 4;
int count = 0;
while(A) {
    A = A & (A-1);
    count++;
}    
cout <<  count;

// Output - 1
