#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { 
        string line;
        while (true) {
                getline(cin, line);
                if (line == "") 
                        break;
                        
                int a = atoi(line.c_str()); // преобразуем строку в число
                cout << a * a << endl; // а тут будем теперь выводить квадраты
        }
        return 0;
}
