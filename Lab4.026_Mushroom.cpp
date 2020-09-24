#include <iostream>
#include<string>
using namespace std;
class Grib
{
protected:
    double_t height=15.5;
    double_t weight=0.150;
public:
    Grib()
    {
        cout << "\nGrib\n";
    }
    Grib(double_t x, double_t y) :height(x), weight(y) { cout << "\nGrib (int,int)\n"; }
    int get_h()
    {
        return height;
    }
    int get_w()
    {
        return weight;
    }

    virtual void print()
    {
        cout << "height: " << height << "\nweight:" << weight;
    }
	
    virtual ~Grib()
    {
        cout << "\n~Grib\n";
    }
};
class jadovitue :virtual public Grib
{
protected:
    double_t poison_death_pnt = 10;
public:
    jadovitue()
    {
        cout << "\npoisoned\n";
    }
    jadovitue(double_t p,double_t h,double_t w) : poison_death_pnt(p) ,Grib(h,w) { cout << "\npoisoned(double_t)\n"; }
    ~jadovitue()
    {
        cout << "\n~poisoned\n";
    }
    void print() override
    {
        cout << "\nheight: " << height << "\nweight:" << weight<<"\npoison_death_pnt: "<< poison_death_pnt<<"\n";
    }
};
class normalne :virtual public Grib
{
protected:
    bool taste = false;
public:
    normalne()
    {
        cout << "\nnormalne\n";
    }
    normalne(bool x,double_t h, double_t w) :taste(x),Grib(h,w) { cout << "\nnormalne(bool)\n"; }
    ~normalne()
    {
        cout << "\n~normalne\n";
    }
    void print() override
    {
        cout << "height: " << height << "\nweight:" << weight<<"\ntaste: "<<taste;
    }

};

class myxomor :public jadovitue
{
protected:
    int circ_num=10;//the number of white circles
public:
    myxomor() {
        cout << "\nmyxomor\n";
    }
    myxomor(int x, double_t p, double_t h, double_t w) :circ_num(x),jadovitue(p,h,w) { cout << "\nmyxomor\n"; }
    static int deaths_p_y;
    static void get_stat() {
        cout << deaths_p_y;
    }

    void print() override
    {
        cout << "\nheight: " << height << "\nweight:" << weight << "\npoison_death_pnt: "
    	
    	<< poison_death_pnt << "\ncirc_num"<<circ_num;
    }
	
    ~myxomor()
    {
        cout << "\n~myxomor\n";
    }
};

class borovik :public normalne
{
protected:
    bool is_brown=true;
public:
    borovik() {
        cout << "\nborovik\n";
    }
    borovik(bool is, bool x, double_t h, double_t w) :is_brown(is),normalne(x,h,w)
    {
        cout << "\nborovik(bool)\n";
    }

    void print() override
    {
        cout << "height: " << height << "\nweight:" << weight << "\ntaste: "
    	<< taste<<"\nis brown?: "<<is_brown;
    }
	
    ~borovik()
    {
        cout << "\n~borovik\n";
    }
};

class forest :public myxomor, public borovik
{
    int badn=100;
    int goodn=10;
public:
    forest()
    {
        cout << "\nforest\n";
    }
    forest(int badn, int goodn, bool is, bool x, double_t h, double_t w, int circn, double_t p) :badn(badn), goodn(goodn),borovik(is,x,h,w),myxomor(circn,p,h,w)
    {
        cout << "\nforest(int,int)\n";
    }

    void print() override
    {
        cout << "\nheight: " << height << "\nweight:" << weight << "\npoison_death_pnt: "

            << poison_death_pnt << "\ncirc_num" << circ_num<<"\ntaste: "
    	
            << taste << "\nis brown?: " <<boolalpha<< is_brown<<"\nbad mashrooms number: "<<badn<<"\ngood mushrooms quantity: "<<goodn<<"\n";
    }
	
    ~forest()
    {
        cout << "\n~forest\n";
    }
};


template<class T>
T getV(const string s)
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter a "<<s<<" value: ";
        T a;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения

            return a;
        }
    }
}

int myxomor::deaths_p_y = 100;
int main() {
    int badn = getV<int>("bad mashrooms number: ");
        int goodn = getV<int>("good mushrooms quantity: ");
        system("cls");
        int circn = 10;
    bool is_brown = true;
        bool is_taste = true;
    double_t height = 15.5; 
        double_t weight = 0.150; 
        double_t poisoned_strong = 0.99099;//%
	
    forest x(badn,goodn,is_brown,is_taste,height,weight,circn,poisoned_strong);
    x.print();
}
