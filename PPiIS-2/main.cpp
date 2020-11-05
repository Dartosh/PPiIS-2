#include <iostream>

using namespace std;


class Unit
{
public:

	virtual const int CheckPopulation(const Unit& value) = 0;

	virtual const Unit& operator+(const Unit& value) = 0;


private:
};

class Country : public Unit
{
public: 

private:
	int population;
	double square;
	char capital;
};

int main()
{


	system("pause");
	return 0;
}