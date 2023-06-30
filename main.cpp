#define CURRENT_VERSION 1.0
#define EXAMPLE_NUMBER  79958970861

#include "files/libs.h"
#include "files/services.h"
#include "files/functions.h"

int main(void)
{
    system("mode con cols=80 lines=25");
    cout << "PtsBomber " << CURRENT_VERSION << " by Patysoncick\n" << endl;

    cout << "Выбери действие(для справки введи 'h')" << endl;
    actionChoice:
    cout << ">>> ";
    char currentAction;
    cin >> currentAction;
    cout << endl;

    switch(currentAction)
    {
        case 'a':
            phoneEntering:
            cout << "Введите номер телефона(например: " << EXAMPLE_NUMBER << "): ";
            cin >> enteredPhone;
            if(enteredPhone.size() != 11)
            {
                cout << "Телефон введён неправильно" << endl;
                goto phoneEntering;
            }
            attackMode();

            goto actionChoice;
            break;

        case 'e':
            cout << "Спасибо за использование, удачного дня ;)" << endl;
            break;

        case 'h':
            cout << "a - Атака" << endl;
            cout << "e - Выход" << endl;
            cout << "h - Справка" << endl;

            goto actionChoice;
            break;

        default:
            cout << "Неизвестное действие\n" << endl;

            goto actionChoice;
            break;
    }

    return 0;
}