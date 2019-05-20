#include <iostream>
#include <string>

using namespace std;

class SuperCar
{
public:
	SuperCar(string, int, int);
	void Move(int);
	void FillGas(int);
	void PrintCarInfo();
protected:
	string name;
	int speed;
	int gas;
};

SuperCar::SuperCar(string inputName, int inputSpeed = 0, int inputGas = 0.0)
{
	name = inputName;
	speed = inputSpeed;
	gas = inputGas;
}

void SuperCar::Move(int gasToUse)
{
	gas -= gasToUse;
	speed += gasToUse;
}

void SuperCar::FillGas(int gasToFill)
{
	gas += gasToFill;
}

void SuperCar::PrintCarInfo()
{
	cout << name << ' ' << speed << ' ' << gas << ' ' << endl;
}

class SuperBus : public SuperCar
{
public:
	SuperBus(string, int, int, int);
	void LoadPassenger(int);
	void UnloadPassenger(int);
	void PrintCarInfo();
protected:
	int passenger;
};

SuperBus::SuperBus(string inputName, int inputSpeed, int inputGas, int inputPassenger = 0)
	:SuperCar(inputName, inputSpeed, inputGas), passenger(inputPassenger)
{
}
void SuperBus::LoadPassenger(int l_Passenger)
{
	passenger += l_Passenger;
}

void SuperBus::UnloadPassenger(int u_Passenger)
{
	passenger -= u_Passenger;
}
void SuperBus::PrintCarInfo()
{
	cout << name << ' ' << speed << ' ' << gas << ' ' << passenger << endl;
}

int main()
{
	SuperCar Car1("Lamborghini");
	SuperBus Bus1("BMW_Bus", 100, 50, 0);

	Car1.PrintCarInfo();
	Bus1.PrintCarInfo();

	Bus1.LoadPassenger(1);
	Bus1.LoadPassenger(2);
	Bus1.LoadPassenger(0);

	Bus1.PrintCarInfo();

	Bus1.UnloadPassenger(1);
	Bus1.UnloadPassenger(1);

	Bus1.PrintCarInfo();

	return 0;
}

// 파일나눠서 진행해볼 것
// 헤더파일 등등