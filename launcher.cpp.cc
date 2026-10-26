#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string base_command =
      "flatpak run --user --filesystem=host org.lili.Fatbox";

  if (argc == 1) {
    std::cout << "[C++23-Key] Прямой запуск оффлайн-контейнера Lili...\n";
    return std::system(base_command.c_str());
  } else {
    std::string full_command = base_command;
    for (int i = 1; i < argc; ++i) {
      full_command += " ";
      full_command += argv[i];
    }

    int result = std::system(full_command.c_str());
    if (result != 0) {
      std::cerr << "[Критическая ошибка] Не удалось запустить контейнер с "
                   "аргументами.\n";
      return 1;
    }
    return 0;
  }
}
