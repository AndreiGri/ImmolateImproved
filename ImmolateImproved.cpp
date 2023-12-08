#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

float getValue(string text) //Метод принимает на вход текст выводимый как запрос и проверяющий корректность введённого значения
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        cout << text;
        float a;
        cin >> a;

        if (cin.fail() || cin.peek() != '\n' || a < .0f || a > 1.f)
        {
            cout << endl;
            cerr << " Ошибка ввода данных\n";
            cout << endl;

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            else // если всё хорошо, то возвращаем a
                return a;
    }
}

int main()
{
    // Изменение кодировки терминала:
    system("chcp 1251 > nul");
    // Установка цвета фона терминала и цвета текста
    system("color 80");

    cout << endl;
    string text1 = " Введите силу Орка: "; //Вызывая метод getValue() запрашивааем и записываем в пременные значения
    float a = getValue(text1);
    string text2 = " Введите мощность сопротивляемости магии: ";
    float b = getValue(text2);

    while (true) {                                     // Бесконечный цикл для запроса силы удара, вычисления оставшегося здоровья Орка
        string text3 = " Введите силу магии удара: ";  // до тех пор пока Орк не будет повержен
        float c = getValue(text3);
        a -= c - (b * c);
        if (a > 0) {
            cout << " Урон: " << c - (b * c) << endl;
            cout << " Сила орка: " << a << endl;
        }
        else break;
    }

    cout << endl;
    cout << " Орк повержен!!!" << endl; // Вывод текста о победе
    cout << endl;

    // Задержка окна консоли:
    system("pause > nul");

    return 0;
}