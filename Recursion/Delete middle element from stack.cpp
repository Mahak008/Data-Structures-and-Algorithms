void solve(stack<int>&st, int N, int count) {
   if(count == N/2) {
      st.pop();
      return;
   }
   int num = st.top();
   st.pop();

   // RECURSIVE CALL
   solve(st, N, count+1);
   st.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
   int count = 0;
   solve(inputStack, N, count);
}

// INPUT : 5, 6, 7, 8 
// OUTPUT:  5, 7, 8 
