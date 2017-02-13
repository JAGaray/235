#include "Vector.h"


	Vector::Vector(unsigned int capacity) {
    capacity_ = capacity;
		arr_ = new int[capacity];
    size_=0;
  }
	Vector::~Vector() {
			delete arr_;
  }
	Vector::Vector(const Vector& rhs) {
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
		arr_ = new int[capacity_];
		for(unsigned i = 0; i < rhs.size_; i++){
			arr_[i] = rhs.arr_[i];
		}
  }
	Vector& Vector::operator=(const Vector& rhs) {
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
		arr_ = new int[capacity_];
		for(unsigned i = 0; i < rhs.size_; i++){
			arr_[i] = rhs.arr_[i];
		}
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
		if(size_ == capacity_){
			resize(capacity_*2);
		}
    arr_[size_] = data;
    size_++;
  }
	bool Vector::remove(const int& data) {
		bool shift = false;
		for (unsigned i = 0; i < size_; i++) {
			if (shift)
				arr_[i-1] = arr_[i];
			if (arr_[i] == data)
				shift = true;
		}
		if (shift)
			size_--;
    return shift;
  }

	void Vector::clear() {
		size_ = 0;
		resize(DEFAULT_CAPACITY);
  }

	int& Vector::operator[](unsigned int pos) {
    return arr_[pos];
  }

	bool Vector::at(unsigned int pos, int& data) const {
    if (pos > size_)
      return false;
    data = arr_[pos];
    return true;
  }



	void Vector::resize(unsigned int capacity) {
		capacity_ = capacity;
		int* temp = new int[capacity_];
		for(unsigned i = 0; i < size_; i++){
			temp[i] = arr_[i];
		}
		delete arr_;
		arr_ = temp;
  }
