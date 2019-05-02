#include "testing.h"

void testing::testingIsInObstacle()
{
	obstacle test_obs;
	// Is not in obstacle
	if (isInObstacle(ofGetWindowWidth() / 2, 300, test_obs) {
		std::cout << "Error: Is not in obstacle" << std::endl;
	}
	if (isInObstacle(ofGetWindowWidth() / 2 + 10, 400, test_obs) {
		std::cout << "Error: Is not in obstacle" << std::endl;
	}

	// Is in obstacle
	if (!isInObstacle(ofGetWindowWidth(), 300, test_obs) {
		std::cout << "Error: Is in obstacle" << std::endl;
	}
	if (!isInObstacle(0, 400, test_obs) {
		std::cout << "Error: Is in obstacle" << std::endl;
	}
}

void testing::testingHasCrashed()
{
	obstacle test_obs;
	ofVec2f top_corner(0, 0);
	ofVec2f size(20, 20);
	// Has not crashed
	if (hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has not crashed" << std::endl;
	}
	top_corner.set(100, 100);
	if (hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has not crashed" << std::endl;
	}

	// Has crashed
	top_corner.set(ofGetWindowWidth() / 2, 100);
	if (!hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has crashed" << std::endl;
	}
	top_corner.set(ofGetWindowWidth() / 2 - 5, 100);
	if (!hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has crashed" << std::endl;
	}
}

void testing::testingShouldDelete()
{
	obstacle test_obs;
	ofVec2f top_corner(10, 10);
	ofVec2f size(20, 20);
	// Should delete
	if (hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has not crashed" << std::endl;
	}
	top_corner.set(100, 100);
	if (hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has not crashed" << std::endl;
	}

	// Should not delete
	top_corner.set(-10, 100);
	if (!hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has crashed" << std::endl;
	}
	top_corner.set(50, -10);
	if (!hasCrashed(top_corner, size, test_obs)) {
		std::cout << "Error: Has crashed" << std::endl;
	}

}