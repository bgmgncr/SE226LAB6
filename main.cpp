#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double e_to_n(double n, int x) {
    auto factorial = [](int k) -> double {
        double result = 1.0;
        for (int i = 2; i <= k; i++) {
            result *= i;
        }
        return result;
    };

    double sum = 1.0;
    vector<double> terms;
    terms.push_back(1.0);

    for (int k = 1; k <= x; k++) {
        double term = pow(n, k) / factorial(k);
        terms.push_back(term);

        sum += pow(-1, k) * term;

        if (k >= 2 && term < 1e-10 * abs(terms[k - 2])) {
            break;
        }
    }

    return sum;
}

int main() {
    double n;
    int x;
    cout << "n: ";
    cin >> n;
    cout << "x: ";
    cin >> x;

    double result = e_to_n(n, x);

    cout << fixed << setprecision(10) << "e^" << n << " = " << result << endl;

    return 0;
}



