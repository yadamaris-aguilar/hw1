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

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  //if there are no items in the list, empty
  if(empty()){
    //create a new item to start off with, head points to it
    head_ = new Item();
    //since only one item, head and tail are pointing to the same
    tail_= head_;
    // tail_->val[tail_->last]=val;
    // tail_->last++;
    // size_++;

  }
  //full array since the last is pointing to the end of array 
  else if(tail_->last == ARRSIZE){
    Item* node = new Item();
    tail_->next = node;
    node->prev = tail_;
    tail_ = node;
    // tail_->val[tail_->last]=val;
    // tail_->last++;
    // size_++;
  }
  //actually add the value in now that you have space where
  //put this outside since each case uses same process
  tail_->val[tail_->last]=val;
  tail_->last++;
  size_++;
}
/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  //empty case
  if(empty()){
    return;
  }
  //removing the value since last from the tail (last linked item) is 
  //is no longer going to be there and size also goes down one
  tail_->last--;
  size_--;
  //if the array only had one array value
  //then you have to delete that item 
  if(tail_->first == tail_->last){
    Item* temp= tail_;
    if(tail_== head_){
      //if there is only one item
      head_ = nullptr;
      tail_= nullptr;
    }
    else{
      tail_= tail_-> prev;
      tail_->next = nullptr;
    }
    delete temp;
  }
}
/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    //if list is empty you need to create a new item 
    //and add the value to the back (video suggestion)
    if(empty()){
      head_=new Item();
      tail_=head_;
      head_->val[ARRSIZE-1]=val;
      head_->first = ARRSIZE-1;
      head_->last = ARRSIZE;
      size_++;
    }
    //if there is space in front of the array 
    //remember that push front will use head_ compared to
    //push back that used tail_ since that would hold end of array values
    else if(head_->first >0){
      head_->first--;
      head_->val[head_->first] = val;
      size_++;
    }
    //if the head_ list is full and you have to allocate a new item
    //in front of the already head_ to make space 
    else{
      //creating a new item and placing it in front
      Item* temp = head_; //dont lose your head
      Item* node = new Item();
      //since node is at the front then head points to it and so prev is null
      node->prev = nullptr;
      node ->next = temp;
      temp->prev = node;
      head_ = node;

      //insert value into the array in item just allocated
      node->val[ARRSIZE-1]= val;
      node->first = ARRSIZE-1;
      node->last = ARRSIZE;
      size_++;
    }
  }
  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  //if the list is empty, do nothing, nothing to pop
  void ULListStr::pop_front(){
    if(empty()){
      return;
    }
    //deleting a value from array by changing the first and last
    //from head since its pop front
    head_->first++;
    size_--;
    //if head is now empty since there was only one value in head 
    //and after pop front, its deleted
    if(head_->first == head_->last){
      Item* temp= head_;
      //if there is another item in the list
      if(head_ != tail_){
        head_= head_->next;
        head_->prev = nullptr;
      }
      //if there isnt another item in the list
      else{
      head_=nullptr;
      tail_=nullptr;
      }
    delete temp;
    }
  }

/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   **/
std::string const & ULListStr::back() const{
  //empty case? - OH 
  return tail_->val[tail_->last-1];
}
/**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}
 /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  //out of bounds and return null for non existent location
  if(loc >= size_){
    return nullptr;
  }
  Item* num = head_;
  size_t total =0;

  while(num != nullptr){
    size_t size_of_array = num->last - num->first;

    //if location is less than the previous arrays amount in other lists (total)
    //added to the size of the array that is it currently in, then that make_random_seed_vector
    //that the list it is in now is the array that has the loc needed
    if(loc < total + size_of_array){
      size_t ind = loc - total;
      return &num->val[num->first + ind];
    }
    //if the location is not in the current array of the list
    //then num should walk over to the next item in the list 
    total+=size_of_array;
    num= num->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

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
