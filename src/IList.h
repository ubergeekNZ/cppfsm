#ifndef ILIST_H_
#define ILIST_H_

template<class T>
class IList {
 public:
  virtual ~IList() {}
  virtual bool isEmpty() = 0;
  virtual bool isFull() = 0;
  virtual void push(const T& item) = 0;
  virtual bool insert(uint32_t index, T& item) = 0;
  virtual T pop() = 0;
  virtual T& peek() = 0;
  virtual T& peekElement(uint32_t index) = 0;
  virtual void replaceElement(uint32_t index, T& item) = 0;
  virtual void removeFromList(uint32_t index) = 0;
  virtual void reset() = 0;
  virtual uint32_t sizeOfList() = 0;
  virtual void deallocate() = 0;
};

#endif  // ILIST_H_
