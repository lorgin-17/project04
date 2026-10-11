#include <iostream>
#include <ctime>
#include "CLI11.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    // создаем описание нашего приложения
    CLI::App app{"Мое приложение"};

    // создаем переменную под имя
    // со значением по умолчанию "странник"
    std::string userName = "странник";
    // объявляем параметр командной строки --name
    // который привязываем к переменной userName
    app.add_option("-n,--name", userName, "имя пользователя");    
    
    // создаем переменную под год
    // со значением по умолчанию "2020"
    int year = 2020;

    // объявляем параметр командной строки --name
    // который привязываем к переменной userName
    app.add_option("-y,--year", year, "год рождения");
   
 // запускаем обработчик командной строки
    CLI11_PARSE(app, argc, argv);
    
    // берем текущее год
    auto t = time(nullptr);
    auto lt = localtime(&t);
    int currentYear = lt->tm_year + 1900;
    
    // считаем возраст
    int age = currentYear - year; 

    cout << currentYear << endl;
    // к этому моменту в userName будет то имя которое переда юзер
    cout << "Привет, " << userName << endl;
    cout<< "ты родился в " << year << " году" << endl
         << "тебе " << age << " лет" << endl;
    return 0;
}
