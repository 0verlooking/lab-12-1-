#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

class MobilePhone {
public:
    std::string model;
    int year;
    int ram;
    int memory;
    double price;

    MobilePhone(std::string m, int y, int r, int mem, double p) 
        : model(std::move(m)), year(y), ram(r), memory(mem), price(p) {}
};

int main() {
    std::vector<MobilePhone> phones = {
        MobilePhone("Model1", 2022, 8, 256, 800),
        MobilePhone("Model2", 2021, 12, 512, 1000),
        MobilePhone("Model3", 2022, 6, 128, 600),
        // Додайте більше телефонів за потреби
    };

    double avg_price = std::accumulate(phones.begin(), phones.end(), 0.0,
    [](const double sum, const MobilePhone& phone) {
        return sum + phone.price;
    }) / phones.size();
    
    std::cout << "Середня ціна: " << avg_price << "\n";

    auto max_memory_phone = std::max_element(phones.begin(), phones.end(), 
    [](const MobilePhone& a, const MobilePhone& b) {
        return a.memory < b.memory;
    });
    
    std::cout << "Модель з максимальним об'ємом пам'яті: " << max_memory_phone->model << "\n";

    double low_range = 600;  // Задайте межі діапазону цін
    double high_range = 1000;

    std::cout << "Моделі, що входять у ціновий діапазон: " << "\n";
    std::for_each(phones.begin(), phones.end(), 
    [=](const MobilePhone& phone) {
        if (phone.price >= low_range && phone.price <= high_range) {
            std::cout << phone.model << "\n";
        }
    });

    int release_year = 2022; // Задайте рік випуску

    int models_in_year = std::count_if(phones.begin(), phones.end(), 
    [=](const MobilePhone& phone) {
        return phone.year == release_year;
    });

    std::cout << "Кількість моделей, випущених в " << release_year << " рік: " << models_in_year << "\n";

    return 0;
}