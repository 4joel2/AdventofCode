#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

int task1(std::vector<int> column1, std::vector<int> column2)
{
    std::sort(column1.begin(), column1.end());
    std::sort(column2.begin(), column2.end());
    int result = 0; 
    for (size_t i = 0; i < column1.size(); ++i)
    {
        if (column2[i] > column1[i])
        {
          result += column2[i] - column1[i];
        } else 
        {
          result += column1[i] - column2[i];
        }
    }
    return result;
}

int task2(std::vector<int> column1, std::vector<int> column2) {
    int result = 0;
    for (int num : column1) {
        int count_num = std::count(column2.begin(), column2.end(), num);
        result += num * count_num;
    }
    return result;
}

int main() {
    std::ifstream file("inputday1"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<int> column1; // To store the first column
    std::vector<int> column2; // To store the second column
    int first, second;

    while (file >> first >> second) { // Read two numbers at a time
        column1.push_back(first); // Add the first number to vector1
        column2.push_back(second); // Add the second number to vector2
    }

    file.close(); // Close the file
    int result1 = task1(column1, column2);
    int result2 = task2(column1, column2);
    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    // Print the vectors to verify
    /*std::cout << "Vector 1: ";
    for (int num : column1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector 2: ";
    for (int num : column2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
*/
    return 0;
  }

