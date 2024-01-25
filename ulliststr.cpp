#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

/**
   * Overwrites the old value at index, pos, with val
   *   - Can run in O(n)
   */

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

/**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

/**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

/**
   * Deletes all items in the list
   */
void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
/*
Adds the given string val to the end of the linked list.
If the list is empty, creates a new Item and sets it as 
both the head and tail. If the tail is full, creates a 
new Item and appends it to the list, updating the tail.
If the tail is not full, adds the string to the current tail.
*/
void ULListStr::push_back(const std::string& val) {

  if(empty()) {
    Item* it 
  }

}

/*Removes the last element from the linked list.
If the list is empty, does nothing.
If the list has one element remaining, 
deletes the tail and sets both head and tail to NULL.
If the last item has one element remaining, moves
 the tail to the previous item and deletes the last item.
If the last item has multiple elements remaining, 
decreases the count of elements.*/
void ULListStr::push_front(const std::string& val){

}

/*Removes the last element from the linked list.
If the list is empty, does nothing.
If the list has one element remaining, 
deletes the tail and sets both head and tail to NULL.
If the last item has one element remaining, moves 
the tail to the previous item and deletes the last item.
If the last item has multiple elements remaining,
decreases the count of elements.*/

void ULListStr::pop_back() {


}

/*Removes the first element from the linked list.
If the list is empty, does nothing.
If the list has one element remaining, deletes 
the head and sets both head and tail to NULL.
If the first item has one element remaining, 
moves the head to the next item and deletes the previous head.
If the first item has multiple elements remaining,
increases the count of elements in the head.*/
void ULListStr::pop_front() {


}

//Returns a reference to the last element of the linked list.
std::string const & ULListStr::back() const {

}

//Returns a reference to the first element of the linked list.
std::string const & ULListStr::front() const {
  
}

//Returns a pointer to the value at a specified location in the linked list.
std::string* ULListStr::getValAtLoc(size_t loc) const {

}
/*Copy assignment operator that
 clears the current object and appends the contents of another ULListStr.*/
ULListStr& ULListStr::operator=(const ULListStr& other) {

}




