#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdlib.h>
#include "IList.h"

template<class T>
class List : IList<T>{
 private:
  uint32_t head;
  uint32_t tail;
  uint32_t List_size;
  T *array;
 public:
  explicit List(uint32_t size);
  bool isEmpty();
  bool isFull();
  void push(const T& item);
  bool insert(uint32_t index, T& item);
  T pop();
  T& peek();
  T& peekElement(uint32_t index);
  void replaceElement(uint32_t index, T& item);
  void removeFromList(uint32_t index);
  void reset();
  uint32_t sizeOfList();
  void deallocate();
};

template<class T>
List<T>::List(uint32_t size): head(0), tail(0) {
  array = new T[size];
  List_size = size;
}

template<class T>
bool List<T>::isEmpty() {
  if (head == tail)
    return true;
  else
    return false;
}

template<class T>
bool List<T>::isFull() {
  if ((tail-head) == (List_size))
    return true;
  else
    return false;
}

template<class T>
void List<T>::push(const T& item) {
  // TODO(Paul) - limit based on the size
  array[tail % List_size] = item;
  tail++;
}

template<class T>
T List<T>::pop() {
  // TODO(Paul) - limit based on the size
  T item = array[head % List_size];
  head++;
  return item;
}

template<class T>
T& List<T>::peek() {
  // TODO(Paul) - limit based on the size
  T& item = array[head % List_size];
  return item;
}

// reset list
template<class T>
void List<T>::reset() {
  head = 0;
  tail = 0;
}

// TODO - need to fix this
template<class T>
bool List<T>::insert(uint32_t index, T& item) {
  
  if (index % List_size)
  {
    tail++;
    for (uint32_t idx = tail; idx >= head + index; idx--) {
      array[idx % List_size] = array[(idx-1) % List_size];
    }

    // insert item into the space
    array[head + index] = item;

    return true;
  }
  return false;
}

// peek index
template<class T>
T& List<T>::peekElement(uint32_t index) {
  T& item = array[(head + index) % List_size];
  return item;
}

template<class T>
void List<T>::replaceElement(uint32_t index, T& item) {
  array[(head + index) % List_size] = item;
}

template<class T>
void List<T>::removeFromList(uint32_t index) {

  for (uint32_t idx = head + index; idx < tail; idx++) {
    array[idx % List_size] = array[(idx+1) % List_size];
  }

  tail--;
}

template<class T>
uint32_t List<T>::sizeOfList() {
  return tail - head;
}

template<class T>
void List<T>::deallocate() {
  delete[] array;
}

#endif  // LIST_H
