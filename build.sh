#!/bin/bash
chmod +x ./build.sh

echo "Компиляция..."
g++ main.cpp -o PtsBomber -lcurl 

echo "Запуск: "
./PtsBomber