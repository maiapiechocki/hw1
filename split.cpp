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

void split(Node*& in, Node*& odds, Node*& evens)

// evens = ptr to head of linked list that will store nodes w even vals
// odds = ptr to head of linked list that will store nodes w odd vals
// in = reference to a ptr to the input linked list that needs to be 
// split into even and odd vals

{
  // base case for empty list:
  if (in == nullptr) {
    odds = nullptr;
    evens = nullptr;
    return;
  }

  // recursive case evens:
  if (in->value % 2 == 0) {
    // if the currrent node's value is even:
    // set 'evens' to nullptr (initialization/reset)
    evens = nullptr; 
    // set 'evens' to the address of the current node
    evens = in;
    // temp to store next ptr to next item before w make 'in' null(null->next DNE)
    Node* temp = in->next; 
    in = nullptr;
    // recursively call split for the next node in the list
    split(temp, odds, evens->next);
    
  } else { //recursive case odds:

    odds=nullptr;
    odds=in;
    Node* temp = in->next; 
    in = nullptr;

    split(temp, odds->next, evens);
    
  }
}
