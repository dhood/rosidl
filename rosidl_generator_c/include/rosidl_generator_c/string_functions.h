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

#ifndef ROSIDL_GENERATOR_C__STRING_FUNCTIONS_H_
#define ROSIDL_GENERATOR_C__STRING_FUNCTIONS_H_

#include <stddef.h>

#include "rosidl_generator_c/string.h"
#include "rosidl_generator_c/visibility_control.h"

#if __cplusplus
extern "C"
{
#endif

ROSIDL_GENERATOR_C_PUBLIC
void
rosidl_generator_c__String__init(rosidl_generator_c__String * str);

ROSIDL_GENERATOR_C_PUBLIC
void
rosidl_generator_c__String__fini(rosidl_generator_c__String * str);

ROSIDL_GENERATOR_C_PUBLIC
bool
rosidl_generator_c__String__assignn(
  rosidl_generator_c__String * str, const char * value, size_t n);

ROSIDL_GENERATOR_C_PUBLIC
bool
rosidl_generator_c__String__assign(
  rosidl_generator_c__String * str, const char * value);

ROSIDL_GENERATOR_C_PUBLIC
bool
rosidl_generator_c__String__Array__init(
  rosidl_generator_c__String__Array * array, size_t size);

ROSIDL_GENERATOR_C_PUBLIC
void
rosidl_generator_c__String__Array__fini(
  rosidl_generator_c__String__Array * array);

ROSIDL_GENERATOR_C_PUBLIC
rosidl_generator_c__String__Array *
rosidl_generator_c__String__Array__create(size_t size);

ROSIDL_GENERATOR_C_PUBLIC
void
rosidl_generator_c__String__Array__destroy(
  rosidl_generator_c__String__Array * array);

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__STRING_FUNCTIONS_H_
