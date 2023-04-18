#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double e_to_n(int x) {
    double n;
    cout << "n: ";
    cin >> n;

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

    cout << fixed << setprecision(10) << "e^" << n << " = " << sum << endl;

    return sum;
}

int overload() {
    int x;
    cout << "x: ";
    cin >> x;

    e_to_n(x);

    return 0;
}
