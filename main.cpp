#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int greatest_common_divisor(int x, int y)
{
    if (y == 0)
        return x;
    return greatest_common_divisor(y, x % y);
}

void convert_decimal(double decimal)
{
    int denom = 1000000;
    int num = decimal * denom;
    for (int i = denom; i>=2; i--)
    {
        if (num % i == 0 && denom % i == 0)
        {
            num = num/i;
            denom = denom/i;
        }
    }

    int common_divisor = greatest_common_divisor(num, denom);

    // Simplify the fraction
    num /= common_divisor;
    denom /= common_divisor;

    if (denom == 1)
        cout << num;
    else
        cout << num << "/" << denom;
    cout << endl;
}
double adding(double n1, double n2) {
    return n1 + n2;
}

double subtracting(double  n1, double n2) {

    return (n1 - n2) ;
}
double multiplying(double n1, double n2) {
    return n1 * n2;
}

double dividing(double n1, double n2) {
    if (n2 == 0)
        return 0;
    else
        return n1 / n2;
}

double return_rational(string& num, int& denom, int& numer, int& pos) {

    numer = stoi(num.substr(0, pos));
    denom = stoi(num.substr(pos + 1));

    return double(numer) / double(denom);
}

int check_rational(string& num) {
    int c = 0;
    int pos = -1;
    for (int i = 0; i < num.length(); ++i) {
        if (num[i] == '/') {
            c++;
            pos = i;
            if (isdigit(num[i]))
                return 0;
        }
    }
    if (c== 1)
        return pos;
    else if (c >1)
        return 0;
    else
        return -1;
}
bool check_non_digits(string& num, int l) {
    int dot =0;
    for (int i = 0; i < l; i++) {
        if (!isdigit(num[i]) && num[i] != '/') {
            if (i == 0 && (num[i] == '+' || num[i] == '-')) {
                continue;
            }
            if (num[i]== '.') {
                dot++;
                continue;
            }
            return true;
        }
    }
    if (dot > 1)
        return true;
    return false;
}

int main() {
    cout << "Welcome to Rational Number Calculator.\n";

    while (true) {
        string n1, n2, operation;
        double result, res_rational_1, res_rational_2;
        cout << "Please enter a rational number operations (or exit): \n";
        cin >> n1;
        if (n1 == "exit") {
            cout << "Thank you for using rational number calculator,\n"
                 << "Have a nice time.\n";
            return 0;
        }
        cin >> operation >> n2;
        bool check_non_1 = check_non_digits(n1, n1.length());
        bool check_non_2 = check_non_digits(n2, n2.length());

        int numerator_1, denominator_1, numerator_2,
                denominator_2,check_rational_1, check_rational_2;
        check_rational_1 = check_rational(n1);
        check_rational_2 = check_rational(n2);
        if(check_non_1 || check_non_2 ||(operation != "+" && operation != "-" &&
                                         operation != "*" && operation != "/" && operation.length() != 1))
        {
            cout << "Invalid operation.\n"
                    "Please try again...\n";
            continue;
        }
        if (check_rational_1 == 0 || check_rational_2 == 0)
        {
            cout << "Invalid operation.\n"
                    "Please try again...\n";
            continue;
        }

        else if(check_rational_1 == -1 && check_rational_2 == -1) {
            res_rational_1 = stod(n1);
            res_rational_2 = stod(n2);
        }
        else {
            res_rational_1 = return_rational(n1, denominator_1, numerator_1, check_rational_1);
            res_rational_2 = return_rational(n2, denominator_2, numerator_2, check_rational_2);
            if (denominator_1 <= 0 || denominator_2 <= 0 || res_rational_2 == 0) {
                cout << "Please enter a Positive number in the denominator\n";
                continue;
            }
        }
        if (operation == "+") {
            result = adding(res_rational_1, res_rational_2);
            convert_decimal(result);

        } else if (operation == "-") {
            result = subtracting(res_rational_1, res_rational_2);
            convert_decimal(result);


        } else if (operation == "*") {
            result = multiplying(res_rational_1, res_rational_2);
            convert_decimal(result);


        } else if (operation == "/") {
            result = dividing(res_rational_1, res_rational_2);
            if (result == 0){
                cout << "Please enter a Positive number in the denominator\n";
            }else
                convert_decimal(result);

        }
    }
}
