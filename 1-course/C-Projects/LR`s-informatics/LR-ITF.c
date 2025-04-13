#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    // Константы
    const double MASS_ATMOSPHERE_KG = 5.15e18; // Масса атмосферы в килограммах
    const double MOLAR_MASS_AIR_GRAMS = 28.97; // Средняя молярная масса воздуха в граммах
    const double AVOGADRO_NUMBER = 6.022e23;   // Число Авогадро

    // Преобразование молярной массы из граммов в килограммы
    double molar_mass_air_kg = MOLAR_MASS_AIR_GRAMS / 1000.0;

    // Расчёт общего числа молекул
    double moles_of_air = MASS_ATMOSPHERE_KG / molar_mass_air_kg;
    double total_molecules = moles_of_air * AVOGADRO_NUMBER;

    // Вывод результата
    printf("Общее количество молекул в атмосфере Земли: %.2e\n", total_molecules);
}