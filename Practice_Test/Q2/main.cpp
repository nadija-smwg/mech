#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printDiameters(const vector<double>& diameters, int count) {
    for (int i = 0; i < count; i++) {
        if (i > 0) {
            cout << '\t';
        }
        cout << diameters[i];
    }
    cout << '\n';
}

int main() {
    char again;

    do {
        int count;
        cout << "Enter the number of shaft measurements: ";
        if (!(cin >> count) || count <= 0) {
            cout << "Enter a positive number of measurements.\n";
            return 1;
        }

        vector<double> diameters(count);
        double sum = 0;

        for (int i = 0; i < count; i++) {
            cout << "Enter diameter " << i + 1 << " (mm): ";
            cin >> diameters[i];
            sum += diameters[i];
        }

        cout << "\nMeasured diameters (mm)\n";
        printDiameters(diameters, count);

        // Insertion sort using adjacent swaps.
        for (int i = 1; i < count; i++) {
            int j = i;
            while (j > 0 && diameters[j - 1] > diameters[j]) {
                swap(diameters[j - 1], diameters[j]);
                j--;
            }
        }

        cout << "Sorted diameters (mm)\n";
        printDiameters(diameters, count);

        double mean = sum / count;
        int middle = count / 2;
        double median = diameters[middle];

        if (count % 2 == 0) {
            median = (diameters[middle - 1] + diameters[middle]) / 2.0;
        }

        cout << fixed << setprecision(2);
        cout << "Mean diameter: " << mean << " mm\n";
        cout << "Median diameter: " << median << " mm\n";
        cout << defaultfloat << setprecision(6);

        cout << "\nAnalyse another batch? (y/n): ";
    } while (cin >> again && (again == 'y' || again == 'Y'));

    return 0;
}
