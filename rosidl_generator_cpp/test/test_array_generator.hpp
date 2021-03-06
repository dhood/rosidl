// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TEST_ARRAY_GENERATOR_HPP_
#define TEST_ARRAY_GENERATOR_HPP_

#include <climits>
#include <random>
#include <type_traits>

/**
 * Helper function to generate a test pattern for boolean type.
 * Alternating true (even index) and false (odd index) pattern.
 * @param C Container (vector, array, etc) to be filled
 * @param size How many elements to fill in. Must size<=container_size
 */
template<
  typename C,
  typename std::enable_if<
    std::is_same<typename C::value_type, bool>::value
  >::type * = nullptr
>
void test_vector_fill(C * container, size_t size, bool val1 = true,
  bool val2 = false)
{
  for (size_t i = 0; i < size; i++) {
    if ((i % 2) == 0) {
      (*container)[i] = val2;
    } else {
      (*container)[i] = val1;
    }
  }
}

/**
 * Helper function to generate a test pattern for integer number types.
 * The template type parameter must be an integer number type.
 * Mininum and maximum values for the type and random values in the middle.
 * @param C Container (vector, array, etc) to be filled
 * @param size How many elements to fill in. Must size<=container_size
 * @param min Minimum value in the rage to fill.
 * @param max Maximum value in the rage to fill.
 */
template<
  typename C,
  typename std::enable_if<
    std::is_integral<typename C::value_type>::value &&
    !std::is_same<typename C::value_type, bool>::value &&
    !std::is_same<typename C::value_type, char>::value &&
    !std::is_same<typename C::value_type, int8_t>::value &&
    !std::is_same<typename C::value_type, uint8_t>::value
  >::type * = nullptr
>
void test_vector_fill(C * container, size_t size,
  typename C::value_type min, typename C::value_type max)
{
  std::default_random_engine rand_generator;
  std::uniform_int_distribution<typename C::value_type> randnum(min, max);

  if (size > 0) {
    (*container)[0] = min;
    for (size_t i = 1; i < size - 1; i++) {
      (*container)[i] = randnum(rand_generator);
    }
    (*container)[size - 1] = max;
  }
}

/**
 * Helper function to generate a test pattern for char type and derivatives.
 * Note: this is necessary because uniform_int_distribution is not defined for
 * char type.
 * Mininum and maximum values for the type and random values in the middle.
 * @param C Container (vector, array, etc) to be filled
 * @param size How many elements to fill in. Must size<=container_size
 * @param min Minimum value in the rage to fill.
 * @param max Maximum value in the rage to fill.
 */
template<
  typename C,
  typename std::enable_if<
    std::is_same<typename C::value_type, char>::value ||
    std::is_same<typename C::value_type, int8_t>::value ||
    std::is_same<typename C::value_type, uint8_t>::value
  >::type * = nullptr
>
void test_vector_fill(C * container, size_t size,
  typename C::value_type min, typename C::value_type max)
{
  std::default_random_engine rand_generator;
  std::uniform_int_distribution<int> randnum(static_cast<int>(min), static_cast<int>(max));

  if (size > 0) {
    (*container)[0] = min;
    for (size_t i = 1; i < size - 1; i++) {
      (*container)[i] = static_cast<typename C::value_type>(randnum(rand_generator));
    }
    (*container)[size - 1] = max;
  }
}

/**
 * Helper function to generate a test pattern for float number types.
 * Mininum and maximum values for the type and random numbers in the middle.
 * @param C Container (vector, array, etc) to be filled
 * @param size How many elements to fill in. Must size<=container_size
 * @param min Minimum value in the rage to fill.
 * @param max Maximum value in the rage to fill.
 */
template<
  typename C,
  typename std::enable_if<
    std::is_floating_point<typename C::value_type>::value
  >::type * = nullptr
>
void test_vector_fill(C * container, size_t size,
  typename C::value_type min, typename C::value_type max)
{
  std::default_random_engine rand_generator;
  std::uniform_real_distribution<typename C::value_type> randnum(min, max);

  if (size > 0) {
    (*container)[0] = min;
    for (size_t i = 1; i < size - 1; i++) {
      (*container)[i] = randnum(rand_generator);
    }
    (*container)[size - 1] = max;
  }
}

#endif  // TEST_ARRAY_GENERATOR_HPP_
