int total_weight(vector<int> &weights) {
  int sum = 0;
  for (int i = 0; i < weights.size(); i++) {
    sum += weights[i];
  }
  return sum;
}
int find_days(vector<int> &weights, int max_weight) {
  int days = 1, load = 0;
  for (unsigned i = 0; i < weights.size(); i++) {
    load += weights[i];
    if (load > max_weight) {
      days++;
      load = weights[i];
    }
  }
  return days;
}
int leastWeightCapacity(vector<int> &weights, int days) {
  int low = *max_element(weights.begin(), weights.end());
  int high = total_weight(weights);
  while (low <= high) {
    int mid = (low + high) / 2;
    int d = find_days(weights, mid);
    if (d <= days) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}
