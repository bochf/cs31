/* Project 3 functions */

#include "parser.h"

#include <string>

using namespace std;

double _deposit(char c) {
  switch (c) {
  case '$':
    return 1.0;
  case 'q':
    return 0.25;
  case 'd':
    return 0.1;
  case 'n':
    return 0.05;
  case 'p':
    return 0.01;
  default:
    return -1.0;
  }
}

double _purchase(char row, char spot) {
  if (spot < '0' || spot > '9') {
    return -1.0;
  }

  switch (row) {
  case 'A':
    return 1.0;
  case 'B':
    return 2.0;
  case 'C':
    return 3.0;
  default:
    return -1.0;
  }
}

bool isValidVendingMachineString(string vendingstring) {
  if (vendingstring.empty()) {
    return false;
  }

  // add a terminating sign to avoid out of range
  string tmp = vendingstring + "##";

  double balance = 0.0; // deposit - purchase
  char action = ' ';    // deposit, purchase, or refund
  size_t curr = 0;      // position of current character

  while (curr < vendingstring.size()) {
    action = tmp.at(curr++);
    switch (action) {
    case 'D':
    case 'M': {
      double amount = _deposit(tmp.at(curr++));
      if (amount < 0) {
        return false;
      }

      balance += amount;
      break;
    }
    case 'P': {
      char row = tmp.at(curr++);
      char spot = tmp.at(curr++);
      double amount = _purchase(row, spot);
      if (amount < 0) {
        return false;
      }

      balance -= amount;
      if (balance < 0) {
        return false;
      }

      break;
    }
    case 'R':
      balance = 0.0;
      break;
    default:
      return false;
    }
  }

  return (action == 'P' || action == 'R');
}

double amountSpent(string vendingstring) {
  if (!isValidVendingMachineString(vendingstring)) {
    return -1.0;
  }

  double spent = 0.0; // total spent
  size_t curr = 0;    // position of current character

  while (curr < vendingstring.size()) {
    switch (vendingstring.at(curr++)) {
    case 'D':
    case 'M':
      ++curr; // skip one char
      break;
    case 'P': {
      char row = vendingstring.at(curr++);
      char spot = vendingstring.at(curr++);
      spent += _purchase(row, spot);
      break;
    }
    default:
      break;
    }
  }

  return spent;
}

double changeReturned(string vendingstring) {
  if (!isValidVendingMachineString(vendingstring)) {
    return -1.0;
  }

  double credit = 0.0;
  double refund = 0.0;
  char action = ' '; // deposit, purchase, or refund
  size_t curr = 0;   // position of current character

  while (curr < vendingstring.size()) {
    action = vendingstring.at(curr++);
    switch (action) {
    case 'D':
    case 'M': {
      credit += _deposit(vendingstring.at(curr++));
      break;
    }
    case 'P': {
      char row = vendingstring.at(curr++);
      char spot = vendingstring.at(curr++);
      credit -= _purchase(row, spot);
      break;
    }
    case 'R': // store the change to refund and reset deposit and purchases
      refund = credit;
      credit = 0.0;
      break;
    default:
      break;
    }
  }

  return action == 'R' ? refund : credit;
}

int howManyItemsBought(string vendingstring) {
  if (!isValidVendingMachineString(vendingstring)) {
    return -1;
  }

  size_t items = 0;
  for (const char action : vendingstring) {
    if (action == 'P') {
      ++items;
    }
  }

  return items;
}
