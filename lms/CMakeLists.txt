
add_executable(main "./main.cpp")

target_link_libraries(main PRIVATE lsq)

add_library(lsq "./least_sq.cpp")
target_link_libraries(lsq PUBLIC Eigen3::Eigen)


add_executable(least_sq_test "./least_sq_test.cpp")
target_link_libraries(least_sq_test PUBLIC GTest::gmock_main lsq)

gtest_discover_tests(
  least_sq_test
  DISCOVERY_TIMEOUT
  60
)
