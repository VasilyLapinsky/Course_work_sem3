
#include <iostream>
#include "Generator.h"
using namespace std;

pair<double, double> make_wanding(pair<double, double> start, bool (*check)(pair<double, double>), int& fi,// fi возвращаемое значение
									vector<bool>& T, double h)
{
	fi = 1;
	int direction = 0;
	try
	{
		while (!check(start))
		{
			fi++;
			generate_vector(T);
			direction = get_direction(T);
			start = get_new_position(start, direction, h);
		}
	}
	catch (exception& e)
	{
		fi = 0;
	}
	return start;
}

double make_u(double (*f)(double, double), bool (*check)(pair<double,double>), 
			pair<double, double> start, int N, vector<bool>& T, double h)
{
	if (N < 1)
		throw exception("Invalid argument N");
	
	if (check(start)) return f(start.first, start.second);
	double result=0;
	int fi = 0;
	pair<double, double> temp;
	for (int i = 0; i < N; ++i)
	{
		temp = make_wanding(start,check, fi, T, h);
		result += (fi * f(temp.first, temp.second)) / N;
	}
	return result;
}


int main()
{

	double x = 0, y = 0;
	cout << "Enter x and y: ";
	cin >> x>>y;
	pair<double, double> temp(x, y);
	int N = 0;
	cout << "Enter N: ";
	cin >> N;
	vector<bool> T{ 1,1,1,1,1,1,1,1,1,1,1,1 };
	try
	{
		double u = make_u([](double x, double y) {return x + y; }, check_pos, temp, N, T, 1);
		cout <<"u( "<<x<<" , "<<y<<" ) = "<< u << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}
