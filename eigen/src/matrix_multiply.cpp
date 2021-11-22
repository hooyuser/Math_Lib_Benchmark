#define EIGEN_USE_MKL_ALL

#include <iostream>
#include <chrono>
#include <format>

#include <Eigen/dense>

using namespace Eigen;

int main() {
	int n = 4000;

	MatrixXd a = MatrixXd::Random(n, n);
	MatrixXd b = MatrixXd::Random(n, n);
	MatrixXd c;

	auto start = std::chrono::high_resolution_clock::now();
	const int N = 100;
	for (int i = 0; i < N; i++) {
		c = a * b;
	}

	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() * 1e-9 / N;
	std::cout << std::format("Elapsed time is: {} (s)/n", time_taken);
	return 0;
}