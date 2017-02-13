#include "Set.h"

	unsigned int Set::size() const {
    return vector_.size();
  };

	Set::~Set() {}

	bool Set::empty() const {
		return vector_.empty();
  };

	bool Set::contains(const int& data) const {
		int temp_data;
		for (unsigned i = 0; i < vector_.size(); i++) {
			if (vector_.at(i, temp_data))
				if (data == temp_data)
					return true;
		}
		return false;
  };

	bool Set::insert(const int& data) {
		if (contains(data))
			return false;
		vector_.push_back(data);
		return true;
  };
	bool Set::remove(const int& data) {
    return vector_.remove(data);
  };

	void Set::clear() {
		vector_.clear();
  };
