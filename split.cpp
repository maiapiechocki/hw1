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

  // recursive case:
  if (in->value % 2 == 0) {
    // if the currrent node's value is even:
    // set 'evens' to nullptr (initialization/reset)
    evens = nullptr; 
    // set 'evens' to the address of the current node
    evens = &*in;

    // recursively call split for the next node in the list
    split(in->next, odds, evens->next);

    // chk if next node is nullptr (end of the list) 
    if (in->next == nullptr)
    {
      // if it is the last even element, set 'evens' to the address of the current node
      evens = &*in;

      // set 'in' to nullptr to signal the end of the list
      in = nullptr;
    }
  } else {
    // if the current node's value is odd:
    // set 'odds' to nullptr (initialization/reset)
    odds=nullptr;

    // set 'odds' to the address of the current node
    odds=&*in;

    // recursively call split for the next node in the list
    split(in->next, odds->next, evens);

    // set 'in' to nullptr to bc we are at the end of the list
    in = nullptr;
  }
}
