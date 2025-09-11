// /*
// CSCI 104: Homework 1 Problem 1

// Use this file to test your split.cpp file.

// Create linked lists and split them with your split() function.

// You can compile this file like this:
// g++ split.cpp test_split.cpp -o test_split
// */

/*
CSCI 104: Homework 1 Problem 1
Test file for split.cpp
*/

#include "split.h"
#include <iostream>

//creating the link list, uses recursion 
Node* buildList(const int arr[], int size); 

// Helper function: print a linked list
void printList(Node* head);

// deletes list so you deallocate the memory
void freeList(Node* head);

//I'm doing three different test cases, One is simple just variety of numbers
//making sure that it actually works. The next is when the list includes 0 to
//to make sure it goes to the evens list. Last test is when there are duplicate
//of numbers to make sure that my code knows what to do

int main() {
  int arr[] = {1, 3, 4, 17, 29, 30, 36, 100}; // sorted list
  int arr_two[]= {0, 1, 3, 7, 10, 19}; //list with 0s
  int arr_three[]= {0,0,3,3,7,9,9,10}; //array with duplicate numbers
  Node* in = buildList(arr, 8);
  Node* in_two = buildList(arr_two,6);
  Node* in_three = buildList(arr_three, 8);

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);


  std::cout << "Odds list: ";
  printList(odds);

  std::cout << "Evens list: ";
  printList(evens);

  std::cout << "Original list (should be empty): ";
  printList(in);

  // Clean up memory
  freeList(odds);
  freeList(evens);

  //second test case starting 
  Node* odds_two = nullptr;
  Node* evens_two = nullptr;

  split(in_two, odds_two, evens_two);


  std::cout << "Odds list: ";
  printList(odds_two);

  std::cout << "Evens list: ";
  printList(evens_two);

  std::cout << "Original list (should be empty): ";
  printList(in_two);

  // Clean up memory
  freeList(odds_two);
  freeList(evens_two);


  Node* odds_three = nullptr;
  Node* evens_three = nullptr;

  split(in_three, odds_three, evens_three);


  std::cout << "Odds list: ";
  printList(odds_three);

  std::cout << "Evens list: ";
  printList(evens_three);

  std::cout << "Original list (should be empty): ";
  printList(in_three);

  // Clean up memory
  freeList(odds_three);
  freeList(evens_three);
}

Node* buildList(const int arr[], int size) {
    //end of list or no size 
    if (size == 0) return nullptr;
    return new Node{arr[0], buildList(arr + 1, size - 1)};
}
void printList(Node* head) {
  //while there are still values in list 
  while(head != nullptr) {
    //print vales
    std::cout << head->value;
    if(head->next != nullptr) std::cout << " -> ";
    //walk down the list 
    head = head->next;
  }
  std::cout << std::endl;
}
void freeList(Node* head) {
  while(head != nullptr) {
    //save the address of the next value after head, kind of 'don't lose your head'
    Node* temp = head->next;
    delete head;
    head = temp;
  }
}