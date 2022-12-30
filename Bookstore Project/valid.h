#include <iostream>

using namespace std;


// validates the input for the menu choice
int getInteger(string prompt) {
  int num = 0;
  cout << prompt;
  cin >> num;
  while (!(cin) || (cin.peek() != '\n')) {  
    cin.clear();
    cin.ignore(100, '\n');
    cout << "\nInvalid input!" << endl;
    cout << prompt;
    cin >> num;
    }
  return num;
  }
