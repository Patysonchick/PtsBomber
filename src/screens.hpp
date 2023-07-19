void startScreen()
{
    cout << "PtsBomber " << CURRENT_VERSION << " by Patysonchick" << DOUBLE_ENDL;

    cout << "Выбери действие(для справки введи 'h')" << endl;
}

#define EXAMPLE_NUMBER "79250480876"
void attackScreen()
{
    phoneEntering:
    cout << "Введите номер телефона(например: " << EXAMPLE_NUMBER << "): ";
    cin >> enteredPhone;
    if(enteredPhone.size() != 11)
    {
        cout << "Телефон введён неправильно" << endl;
        goto phoneEntering;
    }
    cout << "Введи количество повторов: ";
    int *cyclesCount = new int;
    cin >> *cyclesCount;
    cout << endl;

    attack(*cyclesCount);
    delete cyclesCount;
}

void helpScreen()
{
    cout << "GitHub: https://github.com/Patysonchick/PtsBomber.git" << endl;
    cout << "Telegram: https://t.me/PtsBomber" << DOUBLE_ENDL;

    cout << "Команды:" << endl;
    cout << "a - Атака" << endl;
    cout << "h - Справка" << endl;
    cout << "e - Выход" << endl;
}

void exitScreen()
{
    cout << "Спасибо за использование!" << endl;
    cout << "Не забудь поставить звездочку на GitHub, удачного дня ;)" << endl;
}

void unknowScreen()
{
    cout << "Неизвестное действие" << endl;
    cout << "Для справки введи 'h'" << endl;
}

void screenSelecting()
{
    startScreen();

    actionChoice:
    cout << ">>> ";
    char *currentAction = new char;
    cin >> *currentAction;
    cout << endl;

    switch(*currentAction)
    {
        //Атака
        case 'a':
            attackScreen();

            SELECTING_GOTO
            break;
        
        //Помощь
        case 'h':
            helpScreen();

            SELECTING_GOTO
            break;

        //Выход
        case 'e':
            exitScreen();
            break;

        default:
            unknowScreen();

            SELECTING_GOTO
            break;
    }
    delete currentAction;
}