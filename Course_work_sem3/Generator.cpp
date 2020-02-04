#include "Generator.h"
/////////////////////////////////////////////////////////////////////
//Формируем новый массив(который в задаче указан как массив T)
void generate_vector(vector<bool>& v)
{
	int u = 0;
	int k = 1;
	for (int i = 0; i < v.size(); ++i)//Происходит суммирование, формируем u
	{
		if (v[i]) u += k;
		k *= 2;
	}

	u = (u * 7 + 11) % 4087;

	for (int i = v.size() - 1; i > -1; --i)//Записываем двотчное представление в вектор
	{
		v[i] = u % 2;
		u /= 2;
	}
}

int get_direction(const vector<bool>& v)
{
	/*
		формируем число из битов под номирами 0,6,10
		всего может получиться 8 чисел
		т.е. то что нам и нужно
	*/
	return v[1] + v[6] * 2 + v[9] * 4;
}

/////////////////////////////////////////////////////////////////////

pair<double, double> get_new_position(pair<double, double> val, int direction, double h)
{
	switch (direction)
	{
	case 0:// x+h, y
	{
		val.first += h;
		break;
	}
	case 1:// x+h, y-h
	{
		val.first += h;
		val.second -= h;
		break;
	}
	case 2:// x+h, y+h
	{
		val.first += h;
		val.second += h;
		break;
	}
	case 3:// x-h, y
	{
		val.first -= h;
		break;
	}
	case 4:// x-h, y-h
	{
		val.first -= h;
		val.second -= h;
		break;
	}
	case 5:// x-h, y-h
	{
		val.first -= h;
		val.second += h;
		break;
	}
	case 6:// x, y-h
	{
		val.second -= h;
		break;
	}
	case 7:// x, y+h
	{
		val.second += h;
		break;
	}
	default:
		throw exception("Invalid direction!");
	}
	return val;
}

/////////////////////////////////////////////////////////////////////

//Создаем рисунок в программе
vector<pair<double, double>> G = {
	{4,0}, {3,1}, {3,2}, {3,3},
	{2,3}, {1,3}, {0,4}, {0,5},
	{0,6}, {1,7}, {2,7}, {2,8},
	{1,9}, {2, 10}, {3,10}, {4,9},
	{5,9}, {6,9}, {7,10}, {8,10},
	{9,9}, {8,8}, {8,7}, {9,7},
	{10,6}, {1,5}, {10,4}, {9,3},
	{8,3}, {7,3}, {7,2}, {7,1},
	{6,0}, {5,0}
};

bool check_pos(pair<double, double> val)
{
	double x = val.first, y = val.second;
	// Проверяем на входжение в область Г
	if (
		((2 <= x && x <= 8) && (3 <= y && y <= 9)) ||
		((3 <= x && x <= 7) && (1 <= y && y <= 3)) ||
		(((1 <= x && x <= 2) || (8 <= x && x <= 9)) && (3 <= y && y <= 4)) ||
		(((2 <= x && x <= 3) || (7 <= x && x <= 8)) && (9 <= y && y <= 1)) ||
		((4 <= x && x <= 6) && (0 <= y && y <= 1)) ||
		(((0 <= x && x <= 1) || (9 <= x && x <= 10)) && (4 <= y && y <= 6)) ||
		(((x == 1) || (x == 9)) && (y == 9))
		)
	{
		auto res = find(G.begin(), G.end(), val); // Ищем координату среди граничных точек
		/*
			если мы точку не находим то find вернет G.end()
			т.е. res = G.end()
			если res != G.end() значит нашли
		*/
		return res != G.end(); 
	}
	else // координаты находятся за областью
	{
		throw exception("Out of range!");
	}
}