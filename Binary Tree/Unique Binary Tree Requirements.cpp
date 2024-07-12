bool isPossible(int a,int b) {
     if((a==2 || b==2) && a+b!=4) {
         return 1;
     }
     return 0;
}

// Input: a = 1, b = 2
// Output: 1
