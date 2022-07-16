# Homework Project 4
*String Arrays*

## Introduction
As you gain experience with arrays, you'll discover that many applications do the same kinds of things with them (e.g., find where an item is in an array, or check whether two arrays differ). You'll find that it's helpful to have a library of useful functions that manipulate arrays. (For our purposes now, a library is a collection of functions that developers can call instead of having to write them themselves. For a library to be most useful, the functions in it should be related and organized around a central theme. For example, a screen graphics library might have functions that allow you to draw shapes like lines and circles on the screen, move them around, fill them with color, etc. In this view, the Standard C++ library is really a collection of libraries: a string library, a math library, an input/output library, and much more.)

Your assignment is to produce a library that provides functions for many common manipulations of arrays of strings. For each function you must write, this specification will tell you its interface (what parameters it takes, what it returns, and what it must do). It's up to you to decide on the implementation (how it will do it).

The source file you turn in must contain all the functions and a main routine. You can have the main routine do whatever you want, because we will rename it to something harmless, never call it, and append our own main routine to your file. Our main routine will thoroughly test your functions. You'll probably want your main routine to do the same. If you wish, you may write functions in addition to those required here. We will not directly call any such additional functions. If you wish, your implementation of a function required here may call other functions required here.

The program you turn in must build successfully, and during execution, no function (other than main) may read anything from **cin** or write anything to **cout**. If you want to print things out for debugging purposes, write to **cerr** instead of **cout** . When we test your program, we will cause everything written to **cerr** to be discarded instead — we will never see that output, so you may leave those debugging output statements in your program if you wish.

All of the functions you must write take at least two parameters: an array of strings, and the number of items the function will consider in the array, starting from the beginning. For example, in:
```c++
string people[5] = {"howard", "pixie", "barak", "joe", "donald"};
string folks[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "jon", "llewmas", "noj"};
bool b = matchingValuesTogether(folks, 6);
// should return false because of the "jon"s
```

even though the array has 8 elements, only the first 6 had values we were interested in for this call to the function - the function must not examine any of the others.

The one error your function implementations don't have to handle (because they cannot) is when the caller of the function lies and says the array is bigger than it really is. For example in this situation, the function can't possibly know the caller is lying about the number of items in the array:
```c++
string data[5] = {"mama", "mama", "12,", "sansa", "mama"};
bool b = locateMaximum(data, 2500000);   
// this is bad driver code call
// your implementation doesn't have to check for this, because it can't...
```
To make your life easier, whenever this specification talks about strings being equal or about one string being less than or greater than another, the case of letters matters. This means that you can simply use comparison operators like == or < to compare strings. Because of the character collating sequence, all upper case letters come before all lower case letters, so don't be surprised by that result. The [FAQ](http://web.cs.ucla.edu/classes/spring15/cs31/stahl/Projects/4/faq.html) has a note about string comparisons.

## Your task
Here are the functions you must implement:         
```c++ 
int locateMaximum(const string array[], int n);
```
Return the index of the largest item found in the array or -1 if n <= 0.  For example, for the array ```folks[8]``` shown above, ```locateMaximum(folks, 8)```  should return the value 4, corresponding to the index of "tyrion". If there are multiple duplicate maximum values, please return the smallest index that has this maximum value. The maximum value is determined by its dictionary-sorted order which is what < and > use in C++ to determine true and false.
```c++
bool matchingValuesTogether(const string array[], int n);
```
If all the duplicated values found in the array are located one right after the other, return true otherwise false.  If you don't find any duplicated values at all, then return true since you never found any values violating this together-ness principle.  If n <=0, return false.  For example, for the array ```people[5]``` shown above, ```matchingValuesTogether(people, 5)``` should return true.  For the array ```folks[8]```,  ```matchingValuesTogether(folks, 8)``` should return false because the two "jon" values are not located in the array in contiguously located elements, one right after the other.
```c++
bool hasDuplicates(const string array[], int n);
```
If there is a value that is repeatedly found in the array, return true otherwise false or if n <= 0 return false. For example, for the array ```people[5]``` shown above,  ```hasDuplicates(people, 5)``` should return false. For the array ```people[5]``` shown above, ```hasDuplicates(people, 0)``` should return false because the empty array indeed has no duplicates either. For the array ```folks[8]``` shown above, ```hasDuplicates(folks, 8)``` should return true.
```c++
string majorityElement(const string array[], int n);
```
For all the elements in the passed array, identify and return the element that occurs more than n/2 times in the array or return the empty string "" otherwise.   For example, for the array ```folks[8]```  shown above, ```majorityElement(folks, 8)``` should return the empty string since there is no value that occurs five or more times.  For example, for the array data[5] shown above, ```majorityElement(data, 5)``` should return "mama" since it occurs three times.
```c++
bool hasReverse(const string array[], int n);
```
If there is an element in the passed array whose value is the reverse of an existing value found in the array, return true otherwise false or if n <= 0 return false .  For example, for the array ```people[5]``` shown above, ```hasReverse(people, 5)``` should return false.  For example, for the array ```folks[8]``` shown above, ```hasReverse(folks, 8)``` should return true  because "samwell" and its reverse "llewmas" are in the array as well as "jon" and "noj".
```c++
int findLastOccurrence(const string array[], int n, string target);
```
Return the largest index that holds the target value in the array or -1 if it is not found at all or n <= 0.  For example, for the array ```data[5]``` shown above,   ```findLastOccurrence(data, 5, "mama")``` should return the value 4 while ```findLastOccurrence(data, 5, "howard")``` should return -1.
```c++
int countFloatingPointValues(const string array[], int n);
```
Return the total number of floating-point values found in all the array elements of the passed array argument.  For the purpose of this function, a floating-point value should have the form #.#, where # is one of the digits 0-9.  The decimal point is optional but should only be found once for the element to count as a valid floating-point value.  Additionally, the number may contain a single leading + or - sign which is optional.  Return -1 if n <= 0.  For example, for the array ```string data[4] = { "4.4.3.3", "+44", "-33.098", "33.098a" };``` ```countFloatingPointValues(data, 4)``` should return the value 2 while countFloatingPointValues( data, -14 ) should return -1.  According to this specification, all of the following are valid floatingPointValues:  "1.0", "+1", ".0101", "0.0123", "-12".   
```c++
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);
```
For the passed array, replace all occurrences in each element of the character  charToReplace with letterToFill, returning the total number of times the letterToReplace character was replaced by this call or return -1 if n <=0.  For example, for the array ```folks[8]``` shown above, ```replaceAll( folks, 8, 'A', 'Z')``` should return 0 since there are no 'A's in any of the elements.  ```replaceAll( folks, -10, 'A', 'Z' )``` should return -1.  ```replaceAll(folks, 8, 'a', 'Z')``` should return 5 and adjust the array folks to ```{"sZmwell", "jon", "mZrgZery", "dZenerys",  "tyrion", "jon", "llewmZs", "noj"}```

Additionally, I have created a testing tool called CodeBoard to help you check your code.  CodeBoard enables you to be sure you are naming things correctly by running a small number of tests against your code.  Passing CodeBoard tests is not sufficient testing so please do additional testing yourself.  To access CodeBoard for Project 4, please click the link here: https://codeboard.io/projects/124814 (Links to an external site.).  Inside the file named user_functions.cpp, copy and paste your implementation of the assigned functions.  CodeBoard uses its own main( ) to run tests against your code.  Click Compile and Run.  However please be aware that no editing changes can be saved inside CodeBoard.  In this anonymous user configuration, CodeBoard is read-only and does not allow for saving changes.
