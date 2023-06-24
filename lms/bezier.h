#pragma once

#include <Eigen/Core>

inline Eigen::Vector4d GetTVector(double t) {
  auto t2 = t * t;
  auto t3 = t2 * t;
  return Eigen::Vector4d{1, t, t2, t3};
};

// using CubicMatrix = Eigen::Matrix<double, Eigen::Dynamic, 4>;

// inline CubicMatrix TVec(int num_points) {
  
//   auto ts = Eigen::VectorXd::LinSpaced(num_points, 0, 1);
//   CubicMatrix mat(4, num_points);


// }

inline Eigen::Vector4d ReverseTVector(double t) {
  auto tm1 = 1 - t;
  auto tm12 = tm1 * tm1;
  auto tm13 = tm12 * tm1;
  return Eigen::Vector4d{tm13, tm12, tm1, 1};
}

using Matrix24d = Eigen::Matrix<double, 2, 4>;

inline Eigen::Matrix2Xd BezierRaw(const Matrix24d& control_points, int num_points) {
  Eigen::Matrix2Xd interpolated_points(2, num_points);
  auto ts = Eigen::VectorXd::LinSpaced(num_points, 0, 1);
  Eigen::Index index{};
  auto lut = Eigen::Vector4d{1, 3, 3, 1};
  for (const auto& t : ts) {
    Eigen::Vector4d poly = GetTVector(t).array() * ReverseTVector(t).array() * lut.array();
    interpolated_points.col(index) = Eigen::Vector2d{control_points.row(0).dot(poly), control_points.row(1).dot(poly)};
    ++index;
  }
  return interpolated_points;
}
