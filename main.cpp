#include <iostream>
int calculateSum(const int* scores, int size);
double getAverage(int sum, int size);
void addBonus(int* scores, int size, int bonus = 5);
int findHighest(const int* scores, int size);
int countPassed(const int* scores, int size, int passingScore = 70);
// Main function recalling the above functions
int main() {
	std::cout << "Original Scores: ";
	int scores[5] = { 65, 82, 90, 45, 78 };
	for (int i = 0; i < 5; i++) {
		std::cout << scores[i] << " ";
	}
	std::cout << std::endl;
	int sum = calculateSum(scores, 5);
	double average = getAverage(sum, 5);
	addBonus(scores, 5);
	std::cout << "New Scores after adding bonus (+5): ";
	for (int i = 0; i < 5; i++) {
		std::cout << scores[i] << " ";
	}
	std::cout << std::endl;
	int highest = findHighest(scores, 5);
	int passedCount = countPassed(scores, 5);
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;
	std::cout << "Highest Score: " << highest << std::endl;
	std::cout << "Number of Passed Students: " << passedCount << std::endl;
}
//Function Definitions
int calculateSum(const int* scores, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += scores[i];
	}
	return sum;
}
double getAverage(int sum, int size) {
	double average = (double) sum / size; 
	return average;
}
void addBonus(int* scores, int size, int bonus) {
	for (int i = 0; i < size; i++) {
		scores[i] += bonus;
	}
}
int findHighest(const int* scores, int size) {
	int highest = scores[0];
	for (int i = 1; i < size; i++) {
		if (scores[i] > highest) {
			highest = scores[i];
		}
	}
	return highest;
}
int countPassed(const int* scores, int size, int passingScore) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (scores[i] >= passingScore) {
			count++;
		}
	}
	return count;
}
// 1. Pass by value makes a copy of the data. (Used in getAverage function)
// 2. Pass by reference allows the function to modify the original data. (Used in addBonus function)
// 3. Pass by pointer allows the function to modify the original data and also allows for dynamic memory allocation. (used in calculateSum, findHighest, and countPassed functions)
