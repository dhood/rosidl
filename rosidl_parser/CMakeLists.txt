cmake_minimum_required(VERSION 2.8.3)

project(rosidl_parser NONE)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

ament_python_install_package(${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

if(BUILD_TESTING)
  find_package(ament_cmake_nose REQUIRED)
  ament_add_nose_test(nosetests test)
endif()
