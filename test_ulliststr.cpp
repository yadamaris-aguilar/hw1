#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

#include <stdexcept>
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite
void printList(ULListStr& list) {
  for(size_t i = 0; i < list.size(); i++) {
    cout << list.get(i) << " ";
  }
  cout << "size = " << list.size() << endl;
}
int main(int argc, char* argv[])
{
  ULListStr list;

  //test push back if it is on an empty list 
  //and so you have to create a new item 
  cout << "push_back" << endl;
  list.push_back("8");
  printList(list); //8

  //test push back when there are multple things already in the list
  //and so it should add the value to the back of the array
  cout << "push_back" << endl;
  list.push_back("6");
  list.push_back("2");
  printList(list); // [ 8 6 2 ]

  //test push front on a list with values because 
  //then you have to add it to the front
  cout << "push_front" << endl;
  list.push_front("9");
  printList(list); // [ 9 8 6 2]

  //check push front on an empty list because then 
  //you have to create a new item and add to the array 
  cout << "push_front" << endl;
  //create a new list so that it doesn't add to the previous one
  //and we are able to check the function
  ULListStr list2;
  list2.push_front("1");
  printList(list2); // [ 1 ]

  //check if the pop back function works and it should get rid of the 2
  cout << "pop_back" << endl;
  list.pop_back();
  printList(list); 

  //test pop front
  cout << "pop_front" << endl;
  list.pop_front();
  printList(list); 

  cout << " front() and back()" << endl;
  cout << "Front: " << list.front() << endl;
  cout << "Back: " << list.back() << endl; 

  cout << "Back: " << list2.back() << endl;
  cout << "Front: " << list2.back() << endl;

  cout << "get" << endl;
  cout << "Value at loc 1: " << list.get(1) << endl; 
  cout << "Value at loc 1: " << list2.get(0) << endl; 
  
  return 0;
}
