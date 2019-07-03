#include <iostream>
#include "test_runner.h"

using namespace std;

template <typename T>
class DynamicArray {
public:
  DynamicArray();
  DynamicArray(size_t capacity);
  size_t size();
  size_t capacity();
  bool empty();
  T& at(size_t index);
  const T& at(size_t index);
  T& operator[](size_t index);
  T* begin();
  T* end();
  void push_back(const T& value);
  void push_front(const T& value);
  void insert(const T& value);
  T& pop_back();
  T& pop_front();
  void delete(size_t index);
  void remove(const T& value);
  size_t find(const T& value);
  void resize(size_t new_capacity);
  ~DynamicArray();
private:

};

void testConstructor() {
  {
    DynamicArray empty;
    ASSERT_EQUAL(empty.size(), 0u);
    ASSERT_EQUAL(empty.capacity(), 0u);
    ASSERT(empty.begin() == empty.end());
  }
  {
    DynamicArray da(5);
    ASSERT_EQUAL(da.size(), 5u);
    ASSERT_EQUAL(da.capacity(), 5u);
    ASSERT(da.begin != da.end());
    ASSERT(da.end() == da.begin() + 5);
  }
}

int main() {

}
