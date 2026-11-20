#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

void printDiameters(const std::vector<double>& diameters) {
    for (std::size_t i = 0; i < diameters.size(); ++i) {
        if (i > 0) {
            std::cout << '\t';
        }
        std::cout << diameters[i];
    }
    std::cout << '\n';
}

int main() {
    char again;
    do {
        int count;
        std::cout << "Enter the number of shaft measurements: ";
        if (!(std::cin >> count) || count <= 0) {
            std::cerr << "Enter a positive measurement count.\n";
            return 1;
        }

        std::vector<double> diameters(count);
        double total = 0;
        for (int i = 0; i < count; ++i) {
            std::cout << "Enter diameter " << i + 1 << " (mm): ";
            if (!(std::cin >> diameters[i])) {
                std::cerr << "Enter a numeric diameter.\n";
                return 1;
            }
            total += diameters[i];
        }

        std::cout << "\nMeasured diameters (mm)\n";
        printDiameters(diameters);

        for (int i = 1; i < count; ++i) {
            int j = i;
            while (j > 0 && diameters[j - 1] > diameters[j]) {
                std::swap(diameters[j - 1], diameters[j]);
                --j;
            }
        }

        std::cout << "Sorted diameters (mm)\n";
        printDiameters(diameters);

        const int middle = count / 2;
        double median = diameters[middle];
        if (count % 2 == 0) {
            median = (diameters[middle - 1] + diameters[middle]) / 2.0;
        }

        std::cout << std::fixed << std::setprecision(2)
                  << "Mean diameter: " << total / count << " mm\n"
                  << "Median diameter: " << median << " mm\n"
                  << std::defaultfloat << std::setprecision(6);
        std::cout << "\nInspect another batch? (y/n): ";
    } while (std::cin >> again && (again == 'y' || again == 'Y'));
}
