vector<int> asteroidCollision(vector<int>& asteroids) {
  vector<int> ans;
  stack<int> st;
  for (int ast : asteroids) {
    bool destroyed = false;

    while (!st.empty() && ast < 0 && st.top() > 0) {
      if (abs(ast) > st.top()) {
        st.pop(); // Pop the top as it's destroyed by the current asteroid
      } else if (abs(ast) == st.top()) {
        st.pop(); // Both are destroyed
        destroyed = true;
        break;
      } else {
        destroyed = true;
        break;
      }
    }

    if (!destroyed) {
      st.push(ast);
    }
  }
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

// Example 1:
// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

// Example 2:
// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Example 3:
// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

// Pop element only in the case of example 2 and 3
// and destroyed is true only in the case of example 2 and otherwise
