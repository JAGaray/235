#include "Set.h"

/**********************************************************************
Title:						Set.cpp
Author:						Julian Garay
Date Created:			2/10/2017
Class:						Spring 2017, CSCI 235-03, Mon/Wed 535-650
Professor:				Michael Garod
Purpose:					Project #1
Description:			This file is the implementation of Set.h
									It will contain methods to check the size of the set,
									as well as empty it, check if it contains certain data,
									insert or remove data to/from it, and clear it.
************************************************************************/

	/*check size of set by returning vector size*/
	unsigned int Set::size() const {
    return vector_.size();
  };
	/*to empty the set, empty the vector*/
	bool Set::empty() const {
		return vector_.empty();
  };
	/*check if the set contains duplicates. create a temp int named temp_data.
	loop through the vector and call the vector_.at function, passing it both i
	and temp data. if the data at i is equal to temp data then return true,
	else return false.*/
	bool Set::contains(const int& data) const {
		int temp_data;
		for (unsigned i = 0; i < vector_.size(); i++) {
			if (vector_.at(i, temp_data))
				if (data == temp_data)
					return true;
		}
		return false;
  };
	/*to insert a number to the vector, check contains(data). if so return false.
	if it doesn't, pushback the data and return true.*/
	bool Set::insert(const int& data) {
		if (contains(data))
			return false;
		vector_.push_back(data);
		return true;
  };
	/*to remove the set, call the vector_.remove function given the data.*/
	bool Set::remove(const int& data) {
    return vector_.remove(data);
  };
	/*to clear the set just clear the data*/
	void Set::clear() {
		vector_.clear();
  };
