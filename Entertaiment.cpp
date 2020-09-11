#include <iostream>
#include <vector>
#include <algorithm>
//#include 

using namespace std;

#define z1 "Ivan Pozdnyakov\n\n\n"


// Возможно разделение реализации класса в разные файлы, но т.к. я пересылаю только один файл, всё будет вместе
class Building{
public:
	Building(int apartments, int cost )
	{
		SetFlats(apartments);
		SetPrice(cost);
	}
	
	void GetSummSqeure(){
		cout<<summ_sqeure;
	}

	void SetSummSqeure(int summ){
		summ_sqeure = summ;
	}

	void GetFlats()
	{
		cout<<flats;
	}

	void SetFlats(int apartment)
	{
		flats = apartment;
	}

	void GetPrice()
	{
		cout<<price;
	}

	void SetPrice(int cost)
	{
		price = cost;
	}

	virtual void say_hello(){
		cout<<"aaa";
	}
	
	~Building(){

	}

private:
	          //доступны только классу которому они принадлежат
	int flats;
	float price;
	float summ_sqeure;
	int mobile_number;

protected:
           // доступны только классу и дочерним классам
	friend int GetPrice(Building bb );
};

// нарушение инкапсуляции
int GetPrice( Building bb ){
	return bb.price;
}

class Flat: public Building{
public:
	Flat(): Building(total, number )
	{

	}

    void say_hello()
	{
		cout << "Hello world!" << endl;
    }

	void GetRooms()
	{
		cout<<total;
	}

	//template <typename T>
	double SetRooms()
	{
		//расчёт квадратных метров в каждой комнате
		vector <double> area;
		bool flag = true;
		double cout_rooms = 0;
		short i = 0;
		double total = 0;

		cout<<"\n\nInput 0 if there is not anymore rooms\n";
		while (flag == true)
		{
			cout<<"Square "<< i+1 <<" room = ";
			cin>> cout_rooms;
			i++;
			if(cout_rooms == 0)
			{
				flag = false;
				break;
			}
			area.push_back(cout_rooms);
		}
		//sort(area.begin() , area.end());
		
		for(int i = 0; i < area.size(); i++){
			total += area[i];
		}
		return total;
	}

	void GetNumber()
	{
		cout<<number;
	}

	void SetNumber(int n)
	{
		number = n;
	}

private:
	int total;
	int number;
	int square;
};

class s
{
public:

	void GetPrice()
	{
		cout<< this->area();
	}

	virtual int area() = 0;

private:
	int price;
};

class s2: public s
{
public:
	int area()
	{
		return 2;
	}
};
int main(){
	setlocale(0, "");
	system("color 0E");
	cout << z1;

	//s *a = new s2;
	//a->GetPrice();

	//квартиры, площадь
	int count_aparment, square = 0;
	int cost, pr;

	cout << "cost = ";
	cin >> cost;

	cout << "count_aparment = ";
	cin >> count_aparment;
	
	//здание с данными квартирами
	Building b(count_aparment,cost);

	Flat *f;
	f = new Flat[cost];
	
	//расчёт сумарной площади и итоговой цены
	for(int i = 0; i < count_aparment; i++)
	{	
		cout<<"The flat "<<i+1<<"\n";
		float t = f[i].SetRooms();
		square += t;
		cout<< square;
		f[i].SetSummSqeure(t);
	}
	//cout << square;
	b.SetSummSqeure(square);
	pr = GetPrice(b);

	puts("");
	cout << pr * square<< " - total summ of money";

	system("pause");
	return 0;
}
