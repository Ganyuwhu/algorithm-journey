// 求最大公约数和最小公倍数
class Code01_GcdAndLcm {
    // 求最大公约数需要使用辗转相除法
    // 算法：辗转相除法求a和b之间的最大公约数s，假定a > b，并且约定当b = 0时，两者的最大公约数为a
    // 做a和b的带余除法：a = kb + r;
    // 因此r必然可被r整除，从而s是b和r的最大公约数(若存在更大的公约数s'，容易知道此时s'是a和b的最大公约数，矛盾)
    // 继续做带余除法，每次当r!=0时，令a = b， b = r直到带余除法的余数为0，此时b所对应的值就是初始a和b的最大公约数
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // lcm(a) = a * b / gcd(a, b)
    long lcm(int a, int b) {
        return long(a) * b / gcd(a, b);
    }
};
