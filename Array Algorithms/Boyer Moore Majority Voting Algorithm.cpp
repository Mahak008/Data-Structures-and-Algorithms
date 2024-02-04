// Element that appears n/2 times in an array

int candidate = 0, count = 0;
int a[] = { -2, 1, -3, 4, 1, -2, 1, 5, -3, 1, 1 };
int n = sizeof(a)/sizeof(a[0]);

for(int i = 0; i < n; i++) {
    if(count == 0) {
        candidate = a[i];
    }
    else {
        if(a[i] == candidate)
            count++;
        else
            count--;
    }
}
int counter =  0;
for(int i = 0; i < n; i++) {
    if(a[i] == candidate) {
        counter++;
    }
}
if(counter >= n/2) {
    cout << candidate;
}

// Output - 1
