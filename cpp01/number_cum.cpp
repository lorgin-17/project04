#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int x;

    // читаем числа из стандартного ввода, пока они не кончатся
    while (cin >> x)
    {
        sum += x;
    }

    cout << "Сумма: " << sum << endl;
    return 0;
}
