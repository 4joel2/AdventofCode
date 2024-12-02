#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath> // For std::abs

// Function to check if a report is safe
bool isSafe(const std::vector<int>& levels) {
    if (levels.size() < 2) return false;

    bool increasing = true;
    bool decreasing = true;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];
        if (std::abs(diff) < 1 || std::abs(diff) > 3) {
            return false; // Difference constraint violated
        }
        if (diff > 0) decreasing = false; // Not decreasing
        if (diff < 0) increasing = false; // Not increasing
    }

    return increasing || decreasing; // Must be all increasing or all decreasing
}

int main() {
    // Open the file
    std::ifstream inputFile("../Day2/day2input");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    std::vector<std::vector<int>> reports;
    std::string line;

    // Read data line by line
    while (std::getline(inputFile, line)) {
        std::vector<int> report;
        std::istringstream lineStream(line);
        int num;

        // Parse each line into integers
        while (lineStream >> num) {
            report.push_back(num);
        }
        reports.push_back(report);
    }

    inputFile.close();

    // Analyze each report
    int safeCount = 0;
    for (const auto& report : reports) {
        if (isSafe(report)) {
            ++safeCount;
        }
    }

    std::cout << "Number of safe reports: " << safeCount << "\n";

    return 0;
}

