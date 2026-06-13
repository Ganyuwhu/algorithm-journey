# include<iostream>
# include<cmath>
using namespace std;

class Code03_IsSumOfConsecutiveNumbers {
public:
    bool solution(int num) {
        for (int i = 2; i <= sqrt(2 * static_cast<long long>(num)); i++) {
            if ((num - (i * i - i) / 2) % i == 0)
                return true;
        }
         return false;
    }
};

// int main() {
//     Code03_IsSumOfConsecutiveNumbers obj;
//     for (int i = 1; i <= 100; i++) {
//         cout << i << " " << obj.solution(i) << endl;
//     }
// }
