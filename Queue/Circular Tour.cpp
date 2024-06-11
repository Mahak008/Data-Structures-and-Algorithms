struct petrolPump {
    int petrol;
    int distance;
};

class Solution{
  public:
    int tour(petrolPump p[],int n) {
       int deficit = 0;
       int balance = 0;
       int start = 0;
      
       for(int i = 0; i < n; i++) {
           balance += p[i].petrol - p[i].distance;
           if(balance < 0) {
               deficit += balance;
               start = i + 1;
               balance = 0;
           }
       }
       
      if(deficit + balance >= 0) {
           return start;
       }
       return -1;
    }
};

// Petrol: 6, 7, 4, 10, 6, 5
// Distance: 5, 6, 7, 8, 6, 4
// Output: 3
