int n1 = 21, n2 = 100;
int n = min(n1, n2);
for(int i = n; i >= 1; i--) {
    if(n1 % i == 0 && n2 % i == 0) {
        cout << i;
        break;
    }
}

// Output - 
// 1
