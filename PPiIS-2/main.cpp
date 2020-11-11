#include <iostream>
#include <cstring>

using namespace std;

//Main class with all cummon params and methods
class Unit
{
public:
	Unit() :																//Defoult constructor
		_population(0),
		_square(0),
		_name("")
	{}
	Unit(const int population, const double square, const string name) :	//Contructor of the abstract class 
		_population(population),
		_square(square)
	{}

	virtual int CheckPopulation() = 0;										//Check population of the unit
	virtual int ChangePopulation(const int& population) = 0;				//Change value of the population
	virtual double CheckSquare() = 0;										//Check square of the unit
	virtual string GetName() = 0;											//Get name of the unit
	virtual const Unit& operator+(const Unit& value) const = 0;				//Operator overloading to union units

protected:
	string _name;			//Name of the unit
	int _population;		//Value of the population of the unit
	double _square;			//Value of the square of the unit
};

//Class Country, child of Unit
class Country : public Unit
{
public: 
	//Defoult constructor
	Country() : Unit()
	{	
		_capital = "";
	}
	//Constructor of the class Country
	Country(const int population, const double square, const string name, const string capital) : 
		Unit(_population, _square, _name)
	{
		_capital = capital;
	}
	//Check value of square
	double CheckSquare() override
	{
		return _population;
	}
	//Check population
	int CheckPopulation() override
	{
		return _population;
	};
	//Change value of population
	int ChangePopulation(const int& change) override
	{
		_population += change;
	};
	//Check name of country
	string GetName() override
	{
		return _name;
	}
	//Union of countries
	const Unit& operator+(const Unit& other) const override
	{
		Unit* result = new Country(*this);

		//Operation

		return *result;
	}
	//Check the capital of the country
	string GetCapital()
	{
		return _capital;
	}
private:
	string _capital;		//Name of the Capital of the Country
};



int main()
{
	Country a(100, 500, "Belarus", "Minsk");
	Country b(500, 1000, "Russia", "Moscow");
	const Unit& c = a + b;
	system("pause");
	return 0;
}