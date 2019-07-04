/*
** Implementation of dynamic_array class
** using cpp class vector as an example
*/

#include "dynamic_array.h"

template <typename T>
dynamic_array<T>::dynamic_array() {}

template <typename T>
dynamic_array<T>::dynamic_array(size_t size) {}

template <typename T>
size_t dynamic_array<T>::size() const {
  return 0;
}

template <typename T>
size_t dynamic_array<T>::capacity() const {
  return 0;
}

template <typename T>
bool dynamic_array<T>::empty() const {
  return false;
}

template <typename T>
T& dynamic_array<T>::at(size_t index) const {
  T t;
  return t;
}

template <typename T>
T& dynamic_array<T>::operator[](size_t index) const {
  T t;
  return t;
}

template <typename T>
T* dynamic_array<T>::begin() {
  T* t;
  return t;
}

template <typename T>
T* dynamic_array<T>::end() {
  T* t;
  return t;
}

template <typename T>
const T* dynamic_array<T>::begin() const {
  const T* t;
  return t;
}

template <typename T>
const T* dynamic_array<T>::end() const {
  const T* t;
  return t;
}

template <typename T>
void dynamic_array<T>::push_back(const T& value) {}

template <typename T>
T& dynamic_array<T>::pop_back() {
  T t;
  return t;
}

template <typename T>
T& dynamic_array<T>::back() const {
  T t;
  return t;
}

template <typename T>
void dynamic_array<T>::insert(const T& value) {}

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
dynamic_array<T>::~dynamic_array() {}

int main() {
  return 0;
}
