#!/bin/bash

echo "Компиляция..."
g++ main.cpp -o PtsBomber -lcurl 

echo "Запуск: "
./PtsBomber