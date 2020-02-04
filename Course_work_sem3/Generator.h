#pragma once
#include <vector>
#include <utility>
#include <exception>
using namespace std;
// ���������� ����������� ��� ���������
void generate_vector(vector<bool>& v);
int get_direction(const vector<bool>& v);

//���������� ����� �������
pair<double, double> get_new_position(pair<double, double> val, int direction, double h);

// ������� ��� �������� �������
// ������� ��������� ������ �� � ������� ����������� �
// ���� ������ ������������ �����
// ���� �� ������ �� ������� exception("Out of range!")
bool check_pos(pair<double, double> val);