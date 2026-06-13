# include<iostream>
# include<cmath>
using namespace std;

class Code02_EatGrass {
public:
    char f(int grass, char cur) {
        char enemy = cur == 'A' ? 'B' : 'A';
        if (grass < 5) {
            char winner = grass == 0 || grass == 2 ? enemy : cur;
            return winner;
        }

        int eat = 1;
        while (grass >= eat) {
            if (f(grass - eat, enemy) == cur)
                return cur;
            eat *= 4;
        }
        return enemy;
    }

    void print_result(int grass) {
        cout << grass << " " << f(grass, 'A') << endl;
    }

    char solution(int grass) {
        if (grass % 5 == 2 || grass % 5 == 0)
            return 'A';
        return 'B';
    }
};

// int main() {
//     Code02_EatGrass solution;
//     for (int grass = 1; grass <= 50; grass++)
//         solution.print_result(grass);
// }
