#include <iostream>
#include "test_runner.h"

using namespace std;

template <typename T>
class DynamicArray {
public:
  DynamicArray();
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

int main() {

}
