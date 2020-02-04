#pragma once
#include <vector>
#include <utility>
#include <exception>
using namespace std;
// Генерируем направление для блуждания
void generate_vector(vector<bool>& v);
int get_direction(const vector<bool>& v);

//Генерируем новую позицию
pair<double, double> get_new_position(pair<double, double> val, int direction, double h);

// Функция для проверки позиции
// Сначала проверяет входит ли в область определения Г
// Если входят осуществляет поиск
// Если не входят то бросает exception("Out of range!")
bool check_pos(pair<double, double> val);