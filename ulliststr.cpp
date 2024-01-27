#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#define ARRSIZE 10

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
/* Definitions------
head: ptr to the curr head node in the unrolled linked list
head->val: array within 'Item' struct holding multiple string values
Item struct has a next and prev pointer, contains an array of a fixed size
where multiple items can be placed. To track which items are used a pair of indices
is used of the form: [first, last) where first is inclusive
and is the index of the first used item and last is the 
index 1 beyond the last used index. 
*/

void ULListStr::push_back(const std::string& val) {

  if(empty()) // list empty case
  { // creating new item and setting it as head & tail
    Item* item = new Item(); //item = outer list
    head_ = tail_ = item; 
    item->val[0] = val; // first value of val array of new item = val parameter 
    item->last++; // array slot incremented
  }
  else if (tail_ -> last == ARRSIZE) // tail full case
  {
    Item* item = new Item(); 
    // updating tail to next node and appending item
    tail_->next = item;  
    item->prev = tail_;
    tail_ = item;
    item->val[0]=val;
    item->last++;
  }
  else { // tail not full case
  tail_->val[tail_->last] = val; // adds string to current tail
  tail_->last++; // increments last index
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){

  if(empty()) { // list empty case
    Item* item = new Item(); 
    head_=tail_=item;
    item->val[0]= val;
    item->last++;
  }
  // head full case
  // head_->val is an array within the Item struct, holding multiple string values.
  else if (head_->first == 0) { // first element in the current head node is at index 0
    Item* item = new Item(); 
    item->next = head_; 
    head_->prev = item;
    head_ = item;
    item->val[ARRSIZE-1]=val; // adds the value val to the last idx of the val array in the new node
    item->last = ARRSIZE; 
    item->first = ARRSIZE-1; 
  }
  else {
    head_->val[head_->first-1]=val;
    head_->first--;
  }
  size_++;
}

void ULListStr::pop_back() {

  if(empty()) { // list empty case
    return;
  }
    if (size_ == 1) { // linked list has 1 element
      delete tail_; 
      tail_ = nullptr;
      head_ = nullptr;
    }
    else if (tail_->last == 1) { //  last node's array has one element 
      Item* newT = tail_->prev;
      delete tail_;
      tail_ = newT;
      tail_->next=nullptr;
    }
    else { // Item has more than 1 elements
      tail_->last--;
    }
    size_--;
}
  

void ULListStr::pop_front() {
  if(empty()) {
    return;
  }
  if (head_==tail_) { // list has one element
    Item* temp = head_;
    delete temp; 
    tail_ = nullptr;
    head_ = nullptr;
  }
  else if (head_->first == ARRSIZE-1) { // item has one element
    Item* temp = head_;
    head_= temp->next;
    delete temp;
    head_->prev = nullptr;
  }
  else { // item has multiple elements
    head_->first++;
  }
  size_--;
}

//Returns a reference to the last element of the linked list.
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}
//Returns a reference to the first element of the linked list.
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}
//Returns a pointer to the value at a specified location in the linked list
std::string* ULListStr::getValAtLoc(size_t loc) const {

if(loc>=size_ || loc<0){
  return nullptr;
}
Item* curr = head_; 
while(curr!=nullptr){
  if(loc >= curr->last-curr->first) { // more # of elements than loc, thus can traverse
    loc-=(curr->last-curr->first);
    curr = curr-> next; // go to next node
  }
  else {
    return &curr->val[loc+curr->first];
  }
  }
  return nullptr;


}