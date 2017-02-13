#include "Set.h"

	unsigned int Set::size() const {
    return vector_.size();
  };

	bool Set::empty() const {
    return true;
  };

	bool Set::contains(const int& data) const {
    return false;
  };

	bool Set::insert(const int& data) {
		vector_.push_back(data);
		return true;
  };
	bool Set::remove(const int& data) {
    return false;
  };

	void Set::clear() {

  };
