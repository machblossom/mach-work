#include <iostream>
#include <iomanip>
#include <string>
#include "valid.h"

using namespace std;

struct Book {
  int quantity;
  string bookName;
  float bookSubTotal;
  char bookChoice;
};

const double ADD_BOOK = 1;
const double PRINT_LIST = 2;
const double CHECKOUT = 3;
const double ROMANCE_COST = 17.99;
const double SCIFI_COST = 14.99;
const double HORROR_COST = 12.99;
const double OTHER_COST = 9.99;
const double DISCOUNT = 0.80;
const int MAX = 100;
const int MAX_ELEMENTS = 4;

void printWelcome();
void printPrices();
void printMenu();
int getChoice();
void printBookList();
char getBookChoice();
int getBookQuant();
double calcSubTotal(Book books[], int size);
void printList(Book books[], int size);
void printMax(Book books[], int size);
double calcTotal(Book books[], int size);
void printTotal(double total);
void printGoodbye();


int main() {
  int choice = 0;
  Book books[MAX] = {};
  int size = 0;
  double total = 0.0;

  printWelcome();
  printPrices();

  while (choice != CHECKOUT) {
    printMenu();
    choice = getChoice();
    if (choice == ADD_BOOK) {
      printBookList();
      books[size].bookChoice = getBookChoice();
      books[size].bookChoice = toupper(books[size].bookChoice);
      switch (books[size].bookChoice) {
        case 'R': books[size].quantity = getBookQuant();
          books[size].bookSubTotal = calcSubTotal(books, size);
          size++;
          break;
        case 'S': books[size].quantity = getBookQuant();
          books[size].bookSubTotal = calcSubTotal(books, size);
          size++;
          break;
        case 'H': books[size].quantity = getBookQuant();
          books[size].bookSubTotal = calcSubTotal(books, size);
          size++;
          break;
        case 'O': books[size].quantity = getBookQuant();
          books[size].bookSubTotal = calcSubTotal(books, size);
          size++;
          break;
        default: cout << "Invalid choice!";
      }
    } else if (choice == PRINT_LIST) {
      printList(books, size);
      printMax(books, size);
    }
  }

  total = calcTotal(books, size);
  printTotal(total);
  printGoodbye();
}


// prints a welcome message
void printWelcome() {
  cout << "Hello and welcome to the Bookstore!" << endl;
  cout << "We have a great variety of books with different prices!" << endl;
}


// prints the prices of books by genre
void printPrices() {
  cout << "\nRomance Books cost $" << ROMANCE_COST << "!" << endl;
  cout << "Sci-Fi/Fantasy Books cost $" << SCIFI_COST << "!" << endl;
  cout << "Horror Books cost $" << HORROR_COST << "!" << endl;
  cout << "Other Books not within these genres cost $";
  cout << OTHER_COST << "!" << endl;
  cout << "\nChoose from the following list: 1, 2, or 3!" << endl << endl;
}


// prints the list of choices
void printMenu() {
  cout << "\n1. Add Books" << endl;
  cout << "2. Print List of Books" << endl;
  cout << "3. Checkout and Pay" << endl;
}


// retrieves the choice for the menu
int getChoice() {
  int choice;
  choice = getInteger("\nEnter your choice: ");
  while (choice < 1 || choice > 3) {
    cout << "\nInvalid choice!" << endl;
    choice = getInteger("\nEnter your choice: ");
  } return choice;
}


// prints the list of book genres
void printBookList() {
  cout << "\nChoose from the following: R, S, H, or O!" << endl << endl;
  cout << "R. Romance" << endl;
  cout << "S. Sci-Fi/Fantasy" << endl;
  cout << "H. Horror" << endl;
  cout << "O. Other" << endl << endl;
}


// retrieves the choice for the books
char getBookChoice() {
  char letter;
  cout << "Enter your choice: ";
  cin >> letter;
  return letter;
}


// retrieves the amount of books per genre
int getBookQuant() {
  int quant;
  quant = getInteger("\nEnter number of Books: ");
  while (quant < 1) {
    cout << "\nInvalid choice!" << endl;
    quant = getInteger("\nEnter number of Books: ");
  } return quant;
}


// calculates the subtotal 
double calcSubTotal(Book books[], int size) {
  double subTot;
  if (books[size].bookChoice == 'R') {
    subTot = books[size].quantity * ROMANCE_COST;
  } else if (books[size].bookChoice == 'S') {
    subTot = books[size].quantity * SCIFI_COST;
  } else if (books[size].bookChoice == 'H') {
    subTot = books[size].quantity * HORROR_COST;
  } else if (books[size].bookChoice == 'O') {
    subTot = books[size].quantity * OTHER_COST;
  } return subTot;
}


// prints the receipt
void printList(Book books[], int size) {
  cout << fixed << setprecision(2);
  cout << setw(20) << left << "\nBook Genre";
  cout << setw(6) << " QTY";
  cout << setw(13) << " Unit Price";
  cout << setw(10) << " Subtotal" << endl;
  cout << setw(20) << left << "----------";
  cout << setw(6) << "---";
  cout << setw(13) << "----------";
  cout << setw(10) << "--------" << endl;
  for (int i = 0; i < size; ++i) {
    switch (books[i].bookChoice) {
      case 'R': cout << setw(20) << left << "Romance";
        break;
      case 'S': cout << setw(20) << left << "Sci-Fi";
        break;
      case 'H': cout << setw(20) << left << "Horror";
        break;
      case 'O': cout << setw(20) << left << "Other";
        break;
    } cout << setw(6) << books[i].bookSubTotal;
    switch (books[i].bookChoice) {
      case 'R': cout << setw(1) << "$" << setw(12) << ROMANCE_COST;
        break;
      case 'S': cout << setw(1) << "$" << setw(12) << SCIFI_COST;
        break;
      case 'H': cout << setw(1) << "$" << setw(12) << HORROR_COST;
        break;
      case 'O': cout << setw(1) << "$" << setw(12) << OTHER_COST;
        break;
    } cout << setw(1) << "$" << setw(9) << books[i].bookSubTotal << endl;
  }
 }


// this function prints the max number of books the user has gotten
// based on the respective genre
void printMax(Book books[], int size) {
  int max[MAX_ELEMENTS] = {};
  string genre[MAX_ELEMENTS] = {"Romance", "Sci-Fi", "Horror", "Other"};
  int maxNum = 0;
  string bookGenre;
  
  for (int i = 0; i < size; ++i) {
    switch(books[i].bookChoice) {
      case 'R': max[0] += books[i].quantity;
        break;
      case 'S': max[1] += books[i].quantity;
        break;
      case 'H': max[2] += books[i].quantity;
        break;
      case 'O': max[3] += books[i].quantity;
        break;
    }
  } for (int i = 0; i < MAX_ELEMENTS; ++i) {
      if (max[i] > maxNum) {
        maxNum = max[i];
        bookGenre = genre[i];
      }
    }
  if (maxNum == 0) {
    cout << "\nYou currently have no books scanned! :)" << endl;
  } else {
  cout << "\nYour most favorite genre was the " << bookGenre << " genre!" << endl;
  cout << "You have purchased a total of " << maxNum << " books within" << endl;
  cout << "this genre! Congrats!" << endl;
    }
}


// calculates the total price of all books
double calcTotal(Book books[], int size) {
  double tot = 0.0;
  for (int i = 0; i < size; ++i) {
    tot += books[i].bookSubTotal;
  } return tot;
}


// prints the total price of all books
void printTotal(double total) {
  if (total == 0.0) {
    cout << "\nNothing has been purchased!" << endl;
  } else if (total >= 60.0) {
    total *= DISCOUNT;
    cout << "\nSince your total went over $60, you get a 20% discount!" << endl;
    cout << "\nYour new total comes to $" << fixed << setprecision(2);
    cout << total << "!" << endl;
  } else {
    cout << "Your total comes to $" << fixed << setprecision(2);
    cout << total << "!" << endl;
  }
}


// prints a goodbye message
void printGoodbye() {
  cout << "\nThank you for coming to the Bookstore!" << endl;
  cout << "Enjoy your new books! Goodbye!" << endl;
}