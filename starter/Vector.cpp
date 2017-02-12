#include "Vector.h"


	Vector::Vector(unsigned int capacity = DEFAULT_CAPACITY) {
    capacity_ = capacity;
  }
	Vector::~Vector() {
    delete arr_;
  }
	Vector::Vector(const Vector& rhs) {
    arr_ = rhs.arr_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size;
  }
	Vector& Vector::operator=(const Vector& rhs) {
    arr_ = rhs.arr_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
  }

	unsigned int Vector::capacity() {
    return capacity_;
  }
	unsigned int Vector::size() {
    return size_;
  }
	bool Vector::empty() {
    return size == 0;
  }

	void Vector::push_back(const int& data) {
    arr_[size_] = data;
  }
	bool Vector::remove(const int& data) {
    for (int i = 0; i < size_; i++)
      if (arr_[i] == data)
        arr_[i] = null;
  }

	void Vector::clear() {
    delete arr_;
    size_ = 0;
    capacity_ = DEFAULT_CAPACITY;
  }

	int& Vector::operator[](unsigned int pos) {
    return arr_[pos];
  }

	bool Vector::at(unsigned int pos, int& data) const {
    if (pos <= capacity_)
      return true;
    return false;
  }



	void Vector::resize(unsigned int capacity) {

  }
