#pragma once

#include <span>

#include <Eigen/Core>

double GetMedian(std::span<const double> span);

void LeastSq(const Eigen::Matrix2Xd &mat);
