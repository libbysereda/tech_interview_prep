/*
** Implementation of dynamic_array class
** using cpp class vector as an example
*/

#pragma once

#include <cstdlib>

template <typename T>
class dynamic_array {
public:
  dynamic_array();
  dynamic_array(size_t size);
  size_t size() const;
  size_t capacity() const;
  bool empty() const;
  T& at(size_t index) const;
  T& operator[](size_t index) const;
  T* begin();
  T* end();
  const T* begin() const;
  const T* end() const;
  void push_back(const T& value);
  T& pop_back();
  T& back() const;
  void insert(size_t index, const T& value);
  void delete_value(size_t index);
  void remove(const T& value);
  void resize(size_t new_size);
  size_t find(const T& value) const;
  ~dynamic_array();
private:
  size_t size_;
  size_t capacity_;
  T* data_;
};
