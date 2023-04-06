#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));

    vector<int> v1(rand() % 1000 + 1);
    vector<int> v2(rand() % 1000 + 1);

    // Иницијализација на v1 и v2 со случајни вредности
    generate(v1.begin(), v1.end(), []() { return rand() % 1000; });
    generate(v2.begin(), v2.end(), []() { return rand() % 1000; });
    cout<<v1.size()<<endl;
    cout<<v2.size()<<endl;
    try {
        if (v1.size() < v2.size()) {
            throw length_error("Големината на првиот вектор е помала од големината на вториот.");
        }

        copy(v2.begin(), v2.end(), v1.begin());
        
    }
    catch (const length_error& e) {
        cerr << "Исклучок: " << e.what() << endl;
    }

    return 0;
}
