// anixart_achievement_unlocker.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "AnixartSession.hpp"
#include "Logger.hpp"
#include <fstream>

#define countof(arr) (sizeof(arr) / sizeof(arr[0]))

struct AnixartAchievement {
    AnixartAchievement(std::string_view name, std::string_view id) : name(name), id(id) {}
    std::string_view name;
    std::string_view id;
};

AnixartAchievement achievements[] = {
    AnixartAchievement("Привет, я - Аникса!", "5"),
    AnixartAchievement("Аниксарт на Android", "C8V4M-J1X0Z-A3Q9W"),
    AnixartAchievement("Аниксарт на MacOS", "B5N1P-H9K7L-S6D2F"),
    AnixartAchievement("Аниксарт на Windows", "7G3X9-W8Y4Z-Q2R6T"),
    AnixartAchievement("Аниксарт Online", "9F2T6-R5Y8U-I7O1P"),
    AnixartAchievement("Аниксарт поможет", "G1H4J-K9L2M-B5N8P"),
    AnixartAchievement("Аниксарт", "B9N3P-H7K1L-S6D8F")
};

void press_any_key() {
    Logger::log("Нажмите любую кнопку...");
    std::getchar();
}

std::string ask_login() {
    std::string login;
    std::cout << "Выберите логин: ";
    std::cin >> login;
    return login;
}

// Logger :P
AnixartAchievement ask_achievement() {
    for (size_t i = 0; i < countof(achievements); ++i) {
        std::cout << "[" << i << "] " << achievements[i].name << std::endl;
    }
    size_t index;
    std::cout << "Выберите ачивку: ";
    std::cin >> index;
    if (index >= countof(achievements)) {
        Logger::log_error("Неправильный индекс");
        exit(-1);
    }
    return achievements[index];
}

int program_main() {
    int code = 0;
    AnixartSession session(ask_login());
    AnixartAchievement achievement = ask_achievement();

    AchievementCode error_code = session.get_achievement(achievement.id);
    switch (error_code) {
    case AchievementCode::Success:
        Logger::log_info("Ачивка выдана");
        break;
    case AchievementCode::AlreadyGranted:
        Logger::log_error("Ачивка уже получена");
        code = -1;
        break;
    default:
        Logger::log_error("Неизвестная ошибка");
        code = -1;
        break;
    }

    return code;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::atexit(press_any_key);
    try {
        return program_main();
    }
    catch (const network::UrlSessionError& e) {
        Logger::log_error(e.what());
    }
    catch (const std::exception& e) {
        Logger::log_error(e.what());
    }
    catch (...) {
        Logger::log_error("Unknown exception");
    }
    return -1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
