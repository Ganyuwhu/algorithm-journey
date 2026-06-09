# include<iostream>
# include<string>
# include<stack>
using namespace std;

// 含嵌套的表达式求值
// 测试链接 : https://leetcode.cn/problems/basic-calculator-iii/
// 测试链接 : https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4

// 通常来说，要使用两个栈，一个数字栈和一个符号栈，数字栈用来存放计算好的数值，符号栈存储运算符
// 使用一个全局变量pos来维护当前访问的位置，以及cur来保存连续数字表示的值
// cur = cur * 10 + num，每次访问到运算符时将其归0

// 1. 标准解法
// 定义运算符优先级：- <= + <= / <= * < ()；
// 读取到数字时，将其压入数字栈，读取到符号时，将其压入符号栈。
// 若将要压入符号栈的符号的优先级小于栈顶符号的优先级(除非栈顶是左括号)，则从数字栈中弹出两个元素，符号栈中弹出一个元素，将结果压入数字栈，再将符号压入符号栈
// 若压入的是右括号，则依次弹出数字栈和符号栈中的元素，计算并压入结果直到弹出左括号
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        stack<char> operators;
        stack<int> numbers;
        int result = 0;
        int count = 0;
        int valid_nums = true;

        for (char c: s) {
            cout << c;
            if (c <= '9' && c >= '0') {
                count = count * 10 + c - '0';
                valid_nums = true;
            }
            else {
                if (valid_nums) {
                    numbers.push(count);
                    count = 0;
                    valid_nums = false;
                }
                if (c == '-') {
                    while (!operators.empty() && operators.top() != '(')
                        calculate(operators, numbers);
                    operators.push(c);
                }
                if (c == '+') {
                    while (!operators.empty() && operators.top() == '*')
                        calculate(operators, numbers);
                    operators.push(c);
                }
                if (c == '*' || c == '(')
                    operators.push(c);
                if (c == ')') {
                    while (operators.top() != '(')
                        calculate(operators, numbers);
                    operators.pop();
                }
            }
        }
        // 将最后出现的合法数字压入数字栈中
        if (valid_nums)
            numbers.push(count);

        while (!operators.empty())
            calculate(operators, numbers);

        return numbers.top();
    }

    static void calculate(stack<char>& operators, stack<int>& numbers) {
        int n2 = numbers.top();
        numbers.pop();
        int n1 = numbers.top();
        numbers.pop();
        char ope = operators.top();
        operators.pop();
        int result = 0;

        if (ope == '-')
            result = n1 - n2;
        else if (ope == '+')
            result = n1 + n2;
        else if (ope == '*')
            result = n1 * n2;
        else
            result = 0;

        numbers.push(result);
    }
};

// 2. 递归解法
// 将括号内的表达式视为一个因子，用一个函数专门求解括号内的计算结果并按下列规则维护pos：
// （1） 若pos位置是一个数字，计算cur并使pos++；
// （2） 若pos位置是左括号，pos++并调用递归函数，将结果压入数字栈
// （3） 若pos位置是右括号，pos++并返回计算结果
// （4） 其余符号按1.的解法处理

class Solution2 {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        int cur = 0;
        return solveSub(s, cur);
    }

    int solveSub(string s, int& cur) {
        stack<char> operators;
        stack<int> numbers;
        int count = 0;
        bool valid_num = true;
        while (cur < s.size()) {
            if (s[cur] <= '9' && s[cur] >= '0') {
                count = count * 10 + s[cur] - '0';
                valid_num = true;
                cur++;
            } else {
                char c = s[cur++];
                if (valid_num) {
                    numbers.push(count);
                    valid_num = false;
                    count = 0;
                }
                if (c == '-') {
                    while (!operators.empty())
                        calculate(operators, numbers);
                    operators.push(c);
                }
                if (c == '+') {
                    while (!operators.empty() && operators.top() == '*')
                        calculate(operators, numbers);
                    operators.push(c);
                }
                if (c == '*')
                    operators.push(c);
                if (c == '(') {
                    int subResult = solveSub(s, cur);
                    numbers.push(subResult);
                }
                if (c == ')') {
                    // 将最后出现的合法数字压入数字栈中
                    if (valid_num)
                        numbers.push(count);

                    while (!operators.empty())
                        calculate(operators, numbers);

                    return numbers.top();
                }
            }
        }
        // 将最后出现的合法数字压入数字栈中
        if (valid_num)
            numbers.push(count);

        while (!operators.empty())
            calculate(operators, numbers);

        return numbers.top();
    }

    static void calculate(stack<char>& operators, stack<int>& numbers) {
        int n2 = numbers.top();
        numbers.pop();
        int n1 = numbers.top();
        numbers.pop();
        char ope = operators.top();
        operators.pop();
        int result = 0;
        cout << n1 << " " << n2 << endl;

        if (ope == '-')
            result = n1 - n2;
        else if (ope == '+')
            result = n1 + n2;
        else if (ope == '*')
            result = n1 * n2;
        else
            result = 0;

        numbers.push(result);
    }
};
