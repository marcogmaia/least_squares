
#include <gtest/gtest.h>
#include <Eigen/Core>

#include "lms/least_sq.h"

namespace {}

TEST(test, Median) {
  std::vector<double> v{5, 10, 6, 4, 3, 2, 6, 7, 9, 3};
  EXPECT_DOUBLE_EQ(GetMedian(v), 6);
}

TEST(test, t1) {
  Eigen::Matrix2Xd mat(2, 11);
  mat.row(0) << 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
  mat.row(1) << 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;

  LeastSq(mat);
  FAIL();
}
