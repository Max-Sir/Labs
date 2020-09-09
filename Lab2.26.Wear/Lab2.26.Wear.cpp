// Lab2.26.Wear.cpp
//

#include <iostream>
#include<iomanip>
#include <utility>
#include <vector>
using namespace std;

class Wear  // NOLINT(cppcoreguidelines-special-member-functions)
{
	size_t id;
	string name;
	double_t cost;
public:

	double_t get_cost() const;

	string get_name() const;

	void set_name(string x);

	void set_cost(double_t x);


	size_t get_id() const;

	static size_t count;
	Wear(string name = " ", double_t cost = 100.0);
	friend ostream& operator<<(ostream&, const Wear&);
	friend class Customer;
	~Wear();
};

double_t Wear::get_cost() const
{
	return this->cost;
}

string Wear::get_name() const
{
	return this->name;
}

void Wear::set_name(string x)
{
	this->name = std::move(x);
}

void Wear::set_cost(double_t x)
{
	this->cost = x;
}

size_t Wear::get_id() const
{
	return this->id;
}

Wear::Wear(string name, double_t cost): id(++count), name(std::move(name)), cost(cost)
{
}

Wear::~Wear() = default;  // NOLINT(clang-diagnostic-deprecated-copy-dtor)

ostream& operator<<(ostream& out, const Wear& w)
{
	string decor = "-";
	for(int i=0;i<16;++i)
	{
		decor += decor[0];
	}
	out << decor << "\nid: " << w.id << "\nname: " << w.name << "\ncost: " << w.cost<<"$" << endl << decor << endl;
	return out;
}

class Customer
{
public:
	static void set_cost(Wear& w,double_t cost)
	{
		w.cost = cost;
	}
};

size_t Wear::count = 0;

int main()
{
	Wear rj("red jacket", 350);
	Wear bj("blue jeans", 150);
	vector<Wear> wears;
	wears.emplace_back("red jacket", 350);
	wears.emplace_back("blue jacket", 1350.90);
	wears.emplace_back("Machine Gun", 135000.9);
	cout << "\nBefore sales:\n";
	cout << rj<< bj;
	Customer::set_cost(rj, rj.get_cost()*0.25);
	Customer::set_cost(bj, 100.50);
	for(auto it=wears.begin();it<wears.end();++it)
	{
		cout << *it;
		Customer::set_cost(*it, it->get_cost() * static_cast<double_t>(0.75));
	}
	cout << "\nAfter 25% sales:\n";
	for (const auto& it : wears)
	{
		cout << it;
	}
	std::cout<<rj<<bj;
	system("pause");
}