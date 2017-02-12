#include "Vector.h"

class Vector {
public:
	Vector(unsigned int capacity = DEFAULT_CAPACITY) {
    capacity_ = capacity;
  }
	~Vector() {
    delete arr_;
  }
	Vector(const Vector& rhs) {
    arr_ = rhs.arr_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size;
  }
	Vector& operator=(const Vector& rhs) {
    arr_ = rhs.arr_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
  }

	unsigned int capacity() {
    return capacity_;
  }
	unsigned int size() {
    return size_;
  }
	bool empty() {
    return size == 0;
  }

	void push_back(const int& data) {
    arr_[size_] = data;
  }
	bool remove(const int& data) {
    for (int i = 0; i < size_; i++)
      if (arr_[i] == data)
        arr_[i] = null;
  }

	void clear() {
    delete arr_;
    size_ = 0;
    capacity_ = DEFAULT_CAPACITY;
  }

	int& operator[](unsigned int pos) {
    return arr_[pos];
  }

	bool at(unsigned int pos, int& data) const {
    if (pos <= capacity_)
      return true;
    return false;
  }


private:
	int* arr_;
	unsigned int size_;
	unsigned int capacity_;

	static const unsigned int DEFAULT_CAPACITY = 3;

	void resize(unsigned int capacity) {

  }

};
