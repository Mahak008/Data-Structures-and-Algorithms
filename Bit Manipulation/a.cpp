int arr[] = {2,3,7,9,11,2,3,11};
int ans = 0;
int set_bit, x = 0, y = 0;
for(int i = 0;i < 8; i++) {
    ans ^= arr[i];
}

set_bit = ans & ~(ans-1);
for(int i = 0; i < 8;i++) {
    if(arr[i] & set_bit ) {
        x ^= arr[i];
    }
    else {
        y ^= arr[i];
    }
}
cout<<x<<endl<<y;
