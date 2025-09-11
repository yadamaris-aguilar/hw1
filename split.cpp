/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

  /* Add code here */
// WRITE YOUR CODE HERE//
void split(Node*& in, Node*& odds, Node*& evens)
{
  //Base case: no Nodes
  if(in == nullptr){ 
    return; 
  }
  //don't lose your head
  Node* tempnext = in->next; 
  //isolate the one value
  in->next = nullptr;  
  //call split again- recursion
  split(tempnext, odds, evens);
  
  // check if value is even and adds it to evens list
  if(in->value % 2 == 0 ){ 
    in->next = evens; 
    evens =in; 
  } 
    //add to odds linked list
    else{
      in->next = odds;
      odds = in;
    }

  //make sure in is null but not just losing the memory of all values 
  //those are with the new linked list. reminder-check valgrind
  in = nullptr; 
}


