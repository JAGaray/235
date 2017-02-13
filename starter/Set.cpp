#include "Set.h"

	unsigned int Set::size() const {
    return vector_.size();
  };

	bool Set::empty() const {
    return true;
  };

	bool Set::contains(const int& data) const {
		for (unsigned i = 0; i < vector_.size(); i++) {
			if (vector_[i] == data)
				return true;
		}
  };

	bool Set::insert(const int& data) {
		if (contains(data))
			return false;
		vector_.push_back(data);
		return true;
  };
	bool Set::remove(const int& data) {
    return false;
  };

	void Set::clear() {

  };
