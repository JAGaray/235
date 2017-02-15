#include "Vector.h"

/**********************************************************************
Title:						Vector.cpp
Author:						Julian Garay
Date Created:			2/10/2017
Class:						Spring 2017, CSCI 235-03, Mon/Wed 535-650
Professor:				Michael Garod
Purpose:					Project #1
Description:			This file is the implementation of Vector.h
									It will contain methods to check the size of the vector,
									to create copies of the vector, to remove or pushback data
									from/to the vector, shift the data in the vector, and
									empty, clear, resize and manipulate the vector as needed.
									It will also contain a destructor.
************************************************************************/

	//Vector needs a capacity_ of capacity, and the arr_  set to an array of
	//size capacity. Make size_ of vector 0, has no elements in it.
  Vector::Vector(unsigned int capacity) {
    capacity_ = capacity;
		arr_ = new int[capacity];
    size_= 0;
  }
	//destructor needs to delete arr_ pointer
	Vector::~Vector() {
			delete arr_;
  }
	/*We wish to create a copy vector. set capacity_ and size_ to the
	capacity and size of the right hand side vector. set our int pointer arr_
	to a  new int array of size capacity_. Loop through the right hand side array,
	and set the values of array arr_ to the right hand side array.
	Essentially making a copy*/
	Vector::Vector(const Vector& rhs) {
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
		arr_ = new int[capacity_];
		for (unsigned i = 0; i < rhs.size_; i++) {
			arr_[i] = rhs.arr_[i];
		}
  }
	/*Overload the = operator. Do same as above, setting capacity_ and size_
	to the capacity and size of the rhs vector. set our int pointer arr_ to a
	new int array of size capacity_. Loop through rhs array and set values of
	arr_ to the rhs array. Finally, return this vector we're working on via
	pointer this.*/
	Vector& Vector::operator=(const Vector& rhs) {
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
		arr_ = new int[capacity_];
		for (unsigned i = 0; i < rhs.size_; i++) {
			arr_[i] = rhs.arr_[i];
		}
    return *this;
  }
	/*to check capacity, return the capacity_*/
	unsigned int Vector::capacity() const {
    return capacity_;
  }
	/*check size, return size*/
	unsigned int Vector::size() const {
    return size_;
  }
	/*to empty the vector set the size to 0*/
	bool Vector::empty() const {
    return (size_ == 0);
  }
  /*to pushback, first test if size is equal to capacity, if so
	we need to resize the vector, essentially double it. then make the array
	at position size to the data we want to pushback, then increase size.*/
	void Vector::push_back(const int& data) {
		if (size_ == capacity_) {
			resize(capacity_*2);
		}
    arr_[size_] = data;
    size_++;
  }
	/*first I create a bool called shift, that will test if we need to shift data
	after removal. Then, loop through the array. If array at position i is
	equivalent to the value of data, then the bool shift is true. If shift,
	then take the array at i-1 and set it equal to the value at i. effectively
	shifting the data. then if shifted, decrease size. return shift.*/
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
	/*to clear the vector, we need to empty it by setting size to 0. then resize
	back to default capacity.*/
	void Vector::clear() {
		size_ = 0;
		resize(DEFAULT_CAPACITY);
  }
	/*overload [] operator, return array at position*/
	int& Vector::operator[](unsigned int pos) {
    return arr_[pos];
  }
	/*for at: if position is greater than size return false.
	Then set data equal to the value at array[position]. return true*/
	bool Vector::at(unsigned int pos, int& data) const {
    if (pos > size_)
      return false;
    data = arr_[pos];
    return true;
  }


	/*resize is called through pushback, needs to double the vector in size.
	set capacity_ to the default via capacity, then create a new temp int pointer,
	and a new int array of size capacity_ (which should be the default).
	Loop through the temp array and assign it the values of our old arr_.
	After finished, delete the old arr_, set empty old arr_ to temp array.*/
	void Vector::resize(unsigned int capacity) {
		capacity_ = capacity;
		int* temp = new int[capacity_];
		for (unsigned i = 0; i < size_; i++) {
			temp[i] = arr_[i];
		}
		delete arr_;
		arr_ = temp;
  }
