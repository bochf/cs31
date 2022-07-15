#ifndef __PROJECT_3_H__
#define __PROJECT_3_H__

//
// Precisely, to be a valid vending machine string, the string
//
// - can contain only the uppercase letters D, M, P, R, A, B, C, the lowercase
// letters p, n, d, q and $ as well as digit characters 0, 1, 2, 3, 4, 5, 6, 7,
// 8 and 9
// - must start with the uppercase letter D, M or R
// - can only allow a single p, n, d, q or $ following a D or M
// - must end with a purchase or refund
// - each row contains only ten items, valued 0 thru 9, as in A0, A1, A2, A3,
// A4, A5, A6, A7, A8 and A9
// - enough money must be deposited prior to a purchase.  Row A items cost
// $1.00.  Row B items cost $2.00.  Row C items cost $3.00
// - more than one item may be purchased in a vending machine string, if there
// is enough money deposited
// - a purchase is not required for a string to be valid
//
// All of the following are examples of valid vending machine strings:
//
// M$DpR        (no purchase is required, $1.01 would be refunded)
// MqDqMqDqPA3  ($1.00 deposited for a purchase that costs $1.00)
// M$D$PA1PA2   ($2.00 deposited for two purchase that each cost $1.00)
// D$M$PB3      ($2.00 deposited for one purchase that costs $2.00)
// D$PA1R
// D$RR
// All of the following are examples of invalid vending machine strings:
//
// xyz          (bad characters)
// M$           (must end in purchase or refund)
// M$PA1   zzz  (to be valid, all characters must be consumed.  the extra
// characters at the end will make this string invalid) M$RPA3       (no funds
// available since earlier deposit was refunded) MpDdPA1      (not enough funds
// to complete the purchase)
//

#include <string>

/**
 * This function returns true if its parameter is a well-formed vending machine
 * string as described above, or false otherwise.
 */
bool isValidVendingMachineString(std::string vendingstring);

/**
 * If the parameter is a well-formed vending machine string, this function
 * returns the total amount of all purchases.  If the string parameter is not
 * valid, return -1.00.
 */
double amountSpent(std::string vendingstring);

/**
 * If the parameter is a well-formed vending machine string, this function
 * returns the change left over after the string is fully processed.  If the
 * string parameter is not valid, return -1.00.
 */
double changeReturned(std::string vendingstring);

/**
 * If the parameter is a well-formed vending machine string, this function
 * returns the total number of item purchased after the string is fully
 * processed.  If the string parameter is not valid, return -1 .
 */
int howManyItemsBought(std::string vendingstring);

#endif
