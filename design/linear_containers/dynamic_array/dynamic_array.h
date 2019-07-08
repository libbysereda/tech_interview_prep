/*
** Implementation of dynamic_array class
** using cpp class vector as an example
*/

#pragma once

#include <cstdlib>
#include <stdexcept>

template <typename T>
class dynamic_array {
public:
  dynamic_array() = default;
  explicit dynamic_array(size_t size);
  ~dynamic_array();

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
  void insert(size_t index, const T& value);

  T& pop_back();
  void delete_value(size_t index);
  void remove(const T& value);
  void resize(size_t new_size);

  size_t find(const T& value) const;
  T& back() const;
  //void operator=

private:
  size_t size_ = 0;
  size_t capacity_ = 0;
  T* data_ = nullptr;
};

template <typename T>
dynamic_array<T>::dynamic_array(size_t size)
  : data_(new T[size])
  , size_(size)
  , capacity_(size)
{}

template <typename T>
dynamic_array<T>::~dynamic_array() {
  delete[] data_;
}

template <typename T>
size_t dynamic_array<T>::size() const {
  return size_;
}

template <typename T>
size_t dynamic_array<T>::capacity() const {
  return capacity_;
}

template <typename T>
bool dynamic_array<T>::empty() const {
  return (data_ == nullptr);
}

template <typename T>
T& dynamic_array<T>::at(size_t index) const {
  if (index >= size_) throw std::runtime_error("out_of_range");
  return data_[index];
}

template <typename T>
T& dynamic_array<T>::operator[](size_t index) const {
  return data_[index];
}

template <typename T>
T* dynamic_array<T>::begin() {
  return data_;
}

template <typename T>
T* dynamic_array<T>::end() {
  return data_ + size_;
}

template <typename T>
const T* dynamic_array<T>::begin() const {
  return data_;
}

template <typename T>
const T* dynamic_array<T>::end() const {
  return data_ + size_;
}

template <typename T>
void dynamic_array<T>::push_back(const T& value) {
  if (size_ >= capacity_) {
    capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;
    T* new_data = new T[capacity_];

    for (size_t i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
  }
  data_[size_++] = value;
}

template <typename T>
void dynamic_array<T>::insert(size_t index, const T& value) {
}

template <typename T>
T& dynamic_array<T>::pop_back() {
  if (size_ == 0) throw runtime_error("out_of_range");
  return data_[--size_];
}

template <typename T>
void dynamic_array<T>::delete_value(size_t index) {}

template <typename T>
void dynamic_array<T>::remove(const T& value) {}

template <typename T>
void dynamic_array<T>::resize(size_t new_size) {}

template <typename T>
size_t dynamic_array<T>::find(const T& value) const {
  return 0;
}

template <typename T>
T& dynamic_array<T>::back() const {
  return data_[size_ - 1];
}
