#!/bin/bash
#Установочный скрипт

#ВАЖНО!!!
#Запускать из корня проекта, например ~/Документы/PtsBomber$ sh build/build.sh

echo "Установщик PtsBomber"
echo "Компиляция..."
g++ main.cpp -o PtsBomber -lcurl &&

echo "Запуск: " &&
./PtsBomber