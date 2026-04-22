
#include <iostream>
#include <cmath>
#include <vector>
#include <thread>

using namespace std;

void stress_test() {
    double x = 0;
    while(true) {

        x += sqrt(exp(log(sin(x) + 2.0))); 
    }
}

int main() {

    unsigned int n = thread::hardware_concurrency();
    cout << n << "hello, world! " << endl;

    vector<thread> threads;
    for (int i = 0; i < n; ++i) {
        threads.push_back(thread(stress_test));
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
