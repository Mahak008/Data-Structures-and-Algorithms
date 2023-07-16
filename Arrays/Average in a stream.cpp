vector<float> streamAvg(int arr[], int n) {
  vector <float> v;
	float ans = 0, avg = 0;
	for(int i = 0; i < n; i++) {
	  ans += arr[i];
	  avg = ans/(i+1);
	  v.push_back(avg);
	}
	return v;
}
