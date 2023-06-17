project(cmake)

add_executable(cmake_test
  cmake.cc
)

install(TARGETS cmake_test)
