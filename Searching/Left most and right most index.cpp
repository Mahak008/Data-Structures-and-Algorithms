pair<long,long> indexes(vector<long long> v, long long x){

  int start = 0, end = v.size() - 1, mid, f1 = -1, l1 = -1;
  pair<long, long> p;
      
  // First Index
  while(start <= end) {
    mid = (start + end)/2;
    if(v[mid] == x) {
      f1 = mid;
      end = mid - 1;
    }
    else if(v[mid] < x) {
      start = mid + 1;
    }
    else if(v[mid] > x) {
      end = mid - 1;
    }
  }
  p.first = f1;
        
  start = 0, end = v.size() - 1;
        
  // Last Index
  while(start <= end) {
    mid = (start + end)/2;
    if(v[mid] == x) {
      l1 = mid;
      start = mid + 1;
    }
    else if(v[mid] < x) {
      start = mid + 1;
    }
    else if(v[mid] > x) {
      end = mid - 1;
    }
  }
  p.second = l1;
        
  return p;
}
