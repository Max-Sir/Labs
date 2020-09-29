#include<bits/stdc++.h>
using namespace std;
class Grib
{
protected:
    double height=15.5;
    double weight=0.150;
public:
    Grib()
    {
        cout << "\nGrib\n";
    }
    Grib(double x, double y) :height(x), weight(y) { cout << "\nGrib (int,int)\n"; }
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
    double poison_death_pnt = 10;
public:
    jadovitue()
    {
        cout << "\npoisoned\n";
    }
    jadovitue(double p,double h,double w) : poison_death_pnt(p) ,Grib(h,w) { cout << "\npoisoned(double_t)\n"; }
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
    normalne(bool x,double h, double w) :taste(x),Grib(h,w) { cout << "\nnormalne(bool)\n"; }
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
    myxomor(int x, double p, double h, double w) :circ_num(x),jadovitue(p,h,w) { cout << "\nmyxomor\n"; }
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
    borovik(bool is, bool x, double h, double w) :is_brown(is),normalne(x,h,w)
    {
        cout << "\nborovik(bool)\n";
    }

    void print() override
    {
        cout << "height: " << height << "\nweight: " << weight << "\ntaste: "
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
    forest(int badn, int goodn, bool is, bool x, double h, double w, int circn, double p) :badn(badn), goodn(goodn),borovik(is,x,h,w),myxomor(circn,p,h,w)
    {
        cout << "\nforest(int,int)\n";
    }

    void print() override
    {
        cout << "\nheight: " << this->height << "\nweight:" << this->weight << "\npoison_death_pnt: "

            << this->poison_death_pnt << "\ncirc_num" << this->circ_num<<"\ntaste: "
    	
            << this->taste << "\nis brown?: " << this->is_brown<<"\nbad mashrooms number: "<<this->badn<<"\ngood mushrooms quantity: "<<this->goodn<<"\n";
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
        string s;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()||a<0) // если предыдущее извлечение оказалось неудачным,
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
template<>
int getV<int>(const string s)
{
     // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    
        std::cout << "Enter a "<<s<<" value: ";
        string t;
        cin>>t;
        while(t.find_first_not_of("0123456789") != string::npos)
        {
          std::cout << "Oops, that input is invalid.  Please try again.\n";
          cin>>t;
        }
        return stoi(t);
    
}

template<>
double getV<double>(const string s)
{
     // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    
        std::cout << "Enter a "<<s<<" value: ";
        string t;
        cin>>t;
        while(t.find_first_not_of("0.123456789") != string::npos)
        {
          std::cout << "Oops, that input is invalid.  Please try again.\n";
          cin>>t;
        }
        return stod(t);
    
}


int myxomor::deaths_p_y = 100;
int main() {
    int badn = getV<int>("bad mashrooms number: ");
        int goodn = getV<int>("good mushrooms quantity: ");
       // system("cls");
        int circn = getV<int>("good circles quantity: ");
    bool is_brown = getV<bool>("is brown this?(!=0 true, ==0 false): ");;
        bool is_taste = getV<bool>("what about taste(!=0 true, ==0 false) : ");;
    double height = getV<double>("height: "); 
        double weight = getV<double>("weight: ");
        double poisoned_strong = getV<double>("poisoned %: ");;//%
	
    forest x(badn,goodn,is_brown,is_taste,height,weight,circn,poisoned_strong);
    x.print();
}
