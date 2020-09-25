#include <iostream>
#include <vector>
using namespace std;

class Mushroom//B
{
protected:
	double_t height=15.5;
	double_t weight = 0.150;
public:
	virtual void growth() = 0;
	virtual void print() = 0;
	Mushroom(double_t height, double_t weight) :height(height), weight(weight) {  }
	virtual ~Mushroom()
	{
		cout << "\n~Mushroom\n";
	}
};

class Poisoned:public Mushroom//P1
{
protected:
	double_t poison_percent = 100;
public:
	Poisoned(double_t poison_percent,double_t height, double_t weight):
		Mushroom(height,weight),poison_percent(poison_percent)
	{
		cout << "\nPoisoned\n";
	}
	void print() override
	{
		cout << "\nheight: " << height << "\nweight:" << weight<<"\npoison_percent:"<<poison_percent<<"\n";
	}
	
	virtual void growth() override
	{
		height += 0.05;//per day
		weight += 0.010;
	}

	~Poisoned()
	{
		cout << "\n~Poisoned\n";
	}
};

class Fly_Agaric:public Poisoned//myxomor
{
	int circles_num = 10;
public:
	Fly_Agaric(int circles_num, double_t poison_percent, double_t height, double_t weight):circles_num(circles_num),Poisoned(poison_percent,height,weight)
	{
		cout << "\nFly Agaric\n";
	}

	void print() override
	{
		cout << "\nheight: " << height << "\nweight:" << weight << "\npoison_percent:" << poison_percent << "\ncircles number: "<<circles_num<<"\n";
	}
	
	void growth() override
	{
		height += 0.09;//per day
		weight += 0.015;
	}

	~Fly_Agaric()
	{
		cout << "\n~Fly Agaric\n";
	};
};

class White_Mushroom:public Mushroom//p2
{
	double_t age_days = 0;
public:
	White_Mushroom(double_t age_days,double_t height, double_t weight):Mushroom(height,weight),age_days(age_days)
	{
		cout << "\nWhite Mushroom\n";
	}
	~White_Mushroom()
	{
		cout << "\n~White Mushroom\n";
	}
	void print() override
	{
		cout << "\nheight: " << height << "\nweight:" << weight << "\nage: " << age_days << " days\n";
	}
	void growth() override
	{
		height += 0.10;//per day
		weight += 0.020;
	}
};

int main(int argc, char* argv[])
{
	Poisoned c_poisoned(95, 15.25, 0.251);
	Fly_Agaric c_fly_agaric(10, 100, 25.5, 0.562);
	White_Mushroom b_white_mushroom(100, 29.5, 0.499);
	Mushroom** forest = new Mushroom * [3]{&c_poisoned,&c_fly_agaric,&b_white_mushroom};
	int size = 3;
	for(auto i=0;i<size;++i)
	{
		forest[i]->print();
		forest[i]->growth();
		forest[i]->print();
	}
}
