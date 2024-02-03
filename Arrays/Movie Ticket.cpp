int row = 7, col = 5, seat = 31
    
if(row*col < seat) {
  cout << 0 << endl;
}

if(seat % col == 0) {
  cout << col << " " << (seat/col);
}
else {
  cout << (seat%col) << " " << (seat/col) + 1;
}

// Output - 1 7
