#include "Vector.h"


	Vector::Vector(unsigned int capacity) {
    capacity_ = capacity;
    size_=0;
  }
	Vector::~Vector() {
    delete arr_;
  }
	Vector::Vector(const Vector& rhs) {
    arr_ = rhs.arr_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
  }
	Vector& Vector::operator=(const Vector& rhs) {
    arr_ = rhs.arr_;
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    return *this;
  }

	unsigned int Vector::capacity() const {
    return capacity_;
  }
	unsigned int Vector::size() const {
    return size_;
  }
	bool Vector::empty() const {
    return (size_ == 0);
  }

	void Vector::push_back(const int& data) {
    arr_[size_] = data;
    size_++;
  }
	bool Vector::remove(const int& data) {
    for (unsigned i = 0; i < size_; i++)
      if (arr_[i] == data)
        arr_[i] = 0;
    return false;
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
    if (pos > capacity_)
      return false;
    data = arr_[pos];
    return true;
  }



	void Vector::resize(unsigned int capacity) {

  }
