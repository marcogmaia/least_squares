
#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>

double GetMedian(std::span<const double> span) {
  std::vector<double> vec(span.begin(), span.end());
  auto nth = std::next(vec.begin(), vec.size() / 2);
  std::nth_element(vec.begin(), nth, vec.end());
  return *nth;
}

void LeastSq(const Eigen::Matrix2Xd &points) {
  Eigen::MatrixXd A = points.row(0).colwise().homogeneous().transpose();
  Eigen::VectorXd b = points.row(1);
  std::cout << A.colPivHouseholderQr().solve(b) << std::endl;
  auto asd = std::span(b.data(), b.size());
}
