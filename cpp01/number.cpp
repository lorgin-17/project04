#include <iostream>
#include "CLI11.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    CLI::App app{"Мое приложение"};

    // делитель, по умолчанию 1 (то есть выводятся все числа)
    int divider = 1;
    app.add_option("-d,--divider", divider, "делитель");

    // начальный элемент (обязательный)
    int s_number;
    app.add_option("-s,--start", s_number, "нач. эл.")->required();

    // конечный элемент (обязательный)
    int e_number;
    app.add_option("-e,--end", e_number, "кон. эл.")->required();

    CLI11_PARSE(app, argc, argv);

    if (divider == 0)
    {
        cout << "Ошибка: делитель не может быть 0" << endl;
        return 1;
    }

   // cout << "нач. эл.: " << s_number << endl;
   // cout << "кон. эл.: " << e_number << endl;
   // cout << "делитель: " << divider << endl;

    for (int i = s_number; i <= e_number; i++)
    {
        if (i % divider == 0)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
