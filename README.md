# lili313-flatpak-gate


 Это шаблон изолированной среды Python 3.13 + Java IPC Gate

Проходной шаблон для развертывания полностью независимого интерпретатора Python 3.13.17 внутри Linux Mint/Ubuntu без вмешательства в системные зависимости дистрибутива. Решение изолировано через Flatpak и управляется нативным C++23 лаунчером и Java-мостом.

📦 Компоненты репозитория

 org.lili.Fatbox.json  — Автономный манифест сборки контейнера. Пути к архивам относительные.
 LiliGate.java  — Локальный шлюз синхронизации и IPC на Java (сборка лога через аппаратный тик).
 launcher.cpp  — Высокопроизводительный прозрачный мост на C++23 для проброса аргументов CLI.

🛠️ Сборка с нуля

1. Подготовка окружения

 
sudo apt install flatpak flatpak-builder g++
 

2. Сборка бинарного C++ лаунчера

 
g++ -std=c++23 -O3 -march=native launcher.cpp -o lili313
sudo mv lili313 /usr/local/bin/
 

3. Компиляция Java-компонента

 
javac LiliGate.java
 

4. Оффлайн-сборка контейнера Flatpak

Убедитесь, что архив  Python-3.13.17.tar.xz  находится в корневой папке проекта рядом с файлом  .json .

 
flatpak-builder --user --install --force-clean build-dir org.lili.Fatbox.json
 

📋 Использование

Интерактивная консоль Python 3.13:  lili313 
Выполнение локального скрипта хоста:  lili313 test.py 
