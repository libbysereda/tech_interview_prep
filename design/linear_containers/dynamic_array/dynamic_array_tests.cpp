/*
** Tests for dynamic_array class
** using cpp class vector as an example
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// custom testing framework from headers folder
#include "test_runner.h"
#include "dynamic_array.h"

using namespace std;

template <typename T>
vector<T> get_result_vector(const dynamic_array<T>& result) {
  vector<T> result_vector;
  for (const auto i : result) {
    result_vector.push_back(i);
  }
  return result_vector;
}

template <typename T>
void populate_dynamic_array(dynamic_array<T>& da, int counter) {
  for (int i = 0; i < counter; i++) {
    da.push_back(i);
  }
}

void test_constructor() {
  {
    dynamic_array<int> empty;
    ASSERT_EQUAL(empty.size(), 0u);
    ASSERT_EQUAL(empty.capacity(), 0u);
    ASSERT(empty.begin() == empty.end());
  }
  {
    dynamic_array<int> da(5);
    ASSERT_EQUAL(da.size(), 5u);
    ASSERT_EQUAL(da.capacity(), 5u);
    ASSERT(da.begin() != da.end());
    ASSERT(da.end() == da.begin() + 5);
  }
}

void test_size_and_capacity() {
  {
    dynamic_array<int> da;
    da.push_back(1);
    da.push_back(2);
    ASSERT_EQUAL(da.size(), 2u);
    ASSERT_EQUAL(da.capacity(), 2u);
    da.push_back(3);
    ASSERT_EQUAL(da.size(), 3u);
    ASSERT_EQUAL(da.capacity(), 4u);
    da.push_back(4);
    da.push_back(5);
    ASSERT_EQUAL(da.size(), 5u);
    ASSERT_EQUAL(da.capacity(), 8u);
  }
  {
    dynamic_array<int> da(3);
    for (size_t i = 0; i < 3; i++) {
      da[i] = i;
      ASSERT_EQUAL(da.size(), 3);
      ASSERT_EQUAL(da.capacity(), 3);
    }
    da.push_back(4);
    ASSERT_EQUAL(da.size(), 4u);
    ASSERT_EQUAL(da.capacity(), 6u);
  }
}

void test_empty() {
  {
    dynamic_array<int> empty;
    ASSERT(empty.empty());
  }
  {
    dynamic_array<int> non_empty(3);
    ASSERT(!non_empty.empty());
  }
  {
    dynamic_array<int> da(3);
    da.push_back(1);
    ASSERT(!da.empty());
  }
}

void test_at_and_index_operator() {
  dynamic_array<int> da;
  populate_dynamic_array(da, 3);

  ASSERT_EQUAL(da[0], 0);
  ASSERT_EQUAL(da[1], 1);
  ASSERT_EQUAL(da[2], 2);
  da[0] = 3;
  ASSERT_EQUAL(da[0], 3);

  ASSERT_EQUAL(da.at(0), 3);
  try {
    da.at(4);
  } catch (const exception& e) {
    ASSERT_EQUAL(e.what(), string("out_of_range"));
  }
}

void test_begin_end_it() {
  dynamic_array<int> da(5);
  for (int i = 0; i < 5; i++) {
    da[i] = i;
    ASSERT_EQUAL(da.end(), (da.begin() + da.size()));
  }
  auto it = da.begin();

  // reallocate memory for new capacity: capacity = 10, size = 6;
  da.push_back(6);
  ASSERT(it != da.begin());
  ASSERT_EQUAL(da.end(), da.begin() + 6);
  ASSERT_EQUAL(*(da.begin() + 2), 2);
}

void test_push_back() {
  vector<int> expected = {0, 1, 2, 3, 4};
  dynamic_array<int> da;
  populate_dynamic_array(da, 5);

  ASSERT_EQUAL(expected, get_result_vector(da));
}

void test_pop_back() {
  dynamic_array<int> da;
  populate_dynamic_array(da, 5);
  ASSERT_EQUAL(da.pop_back(), 4);
  ASSERT_EQUAL(da.size(), 4u);
  ASSERT_EQUAL(da.capacity(), 8u);
}

void test_back() {
 dynamic_array<int> da(3);
 da.push_back(4);
 ASSERT_EQUAL(da.back(), 4);
}

void test_insert() {
  dynamic_array<int> da;
  populate_dynamic_array(da, 5);

  // insert in the middle
  da.insert(3, 10);
  {
    vector<int> expected = {0, 1, 2, 10, 3, 4};
    ASSERT_EQUAL(expected, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 6u);
  }

  // insert at the end
  da.insert(5, 11);
  {
    vector<int> expected = {0, 1, 2, 10, 3, 4, 11};
    ASSERT_EQUAL(expected, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 7u);
  }
}

void test_delete_value() {
  dynamic_array<int> da;
  populate_dynamic_array(da, 5);

  // delete_value from the middle
  da.delete_value(3);
  {
    vector<int> expected = {0, 1, 2, 4};
    ASSERT_EQUAL(expected, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 4u);
  }

  // delete_value from the end
  da.delete_value(3);
  {
    vector<int> expected = {0, 1, 2};
    ASSERT_EQUAL(expected, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 3u);
  }
}

void test_remove() {
  {
    dynamic_array<int> da;
    for (int i = 0; i < 5; i++) {
      da.push_back(0);
    }
    da.remove(1);
    vector<int> expected = {0, 0, 0, 0, 0};
    ASSERT_EQUAL(expected, get_result_vector(da));
    da.remove(0);
    ASSERT_EQUAL(vector<int>{}, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 0u);
  }
  {
    dynamic_array<int> da;
    populate_dynamic_array(da, 5);
    da[1] = 7;
    da[3] = 7;
    da.remove(7);
    vector<int> expected = {0, 2, 4};
    ASSERT_EQUAL(expected, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 3u);
  }
  {
    dynamic_array<int> da;
    populate_dynamic_array(da, 5);
    da[0] = 7;
    da[4] = 7;
    da.remove(7);
    vector<int> expected = {1, 2, 3};
    ASSERT_EQUAL(expected, get_result_vector(da));
    ASSERT_EQUAL(da.size(), 3u);
  }
}

void test_resize() {
  dynamic_array<int> da;
  populate_dynamic_array(da, 5);
  da.resize(3);
  vector<int> expected = {0, 1, 2};
  ASSERT_EQUAL(expected, get_result_vector(da));
  ASSERT_EQUAL(da.size(), 3u);
  ASSERT_EQUAL(da.capacity(), 8u);

  da.resize(3);
  ASSERT_EQUAL(expected, get_result_vector(da));
  ASSERT_EQUAL(da.size(), 3u);
  ASSERT_EQUAL(da.capacity(), 8u);

  da.resize(0);
  ASSERT_EQUAL(vector<int> {}, get_result_vector(da));
  ASSERT_EQUAL(da.size(), 0u);
  ASSERT_EQUAL(da.capacity(), 8u);
}

void test_find() {
  dynamic_array<int> da;
  populate_dynamic_array(da, 5);
  ASSERT_EQUAL(3, da.find(3));
  da[1] = 3;
  ASSERT_EQUAL(1, da.find(3));
  ASSERT_EQUAL(-1, da.find(7));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, test_constructor);
  RUN_TEST(tr, test_size_and_capacity);
  RUN_TEST(tr, test_empty);
  RUN_TEST(tr, test_at_and_index_operator);
  RUN_TEST(tr, test_begin_end_it);
  RUN_TEST(tr, test_push_back);
  RUN_TEST(tr, test_pop_back);
  RUN_TEST(tr, test_insert);
  RUN_TEST(tr, test_delete_value);
  RUN_TEST(tr, test_remove);
  RUN_TEST(tr, test_resize);
  RUN_TEST(tr, test_find);
  RUN_TEST(tr, test_back);
}
