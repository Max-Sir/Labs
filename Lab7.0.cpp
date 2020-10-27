// Lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;


template<class Key, class Value>
class MapIterator : public std::iterator<std::input_iterator_tag, pair<Key, Value>>
{
public:
    MapIterator(pair<Key, Value>* rhs);
    MapIterator(const MapIterator& it);

    bool operator!=(MapIterator const& other) const;
    bool operator==(MapIterator const& other) const; //need for BOOST_FOREACH 
    typename MapIterator::reference operator*() const;
    MapIterator& operator++();
private:
    pair<Key, Value>* p;
};


template <typename Key, typename Value>
class Map
{
    vector<pair<Key, Value>> vec;
public:
    typedef MapIterator<Key, Value> iterator;

    iterator begin()
    {
        return (iterator(vec.size() ? &vec[0] : nullptr));
    }
    iterator end()
    {
        return iterator(vec.size() ? &vec[0] + vec.size() : nullptr);
    }
    //const_iterator begin() const;
    //const_iterator end() const;


    Map();
    void Add(Key key, Value value);
    void Print();
    void Clear();
    Map& operator=(Map<Key, Value> l);
    Value& operator[](Key key);
};
#pragma region Методы 
template<class Key, class Value>
MapIterator<Key, Value>::MapIterator(pair<Key, Value>* rhs) : p(rhs)
{

}
template<class Key, class Value>
MapIterator<Key, Value>::MapIterator(const MapIterator& it) : p(it.p)
{

}
template<class Key, class Value>
bool MapIterator<Key, Value>::operator!=(MapIterator const& other) const
{
    return p != other.p;
}
template<class Key, class Value>
bool MapIterator<Key, Value>::operator==(MapIterator const& other) const
{
    return p == other.p;
}
template<class Key, class Value>
typename MapIterator<Key, Value>::reference MapIterator<Key, Value>::operator*() const
{
    return *p;
}
template<class Key, class Value>
MapIterator<Key, Value>& MapIterator<Key, Value>::operator++()
{
    ++p;
    return *this;
}
#pragma endregion 



template <typename Key, typename Value >
Map<Key, Value>::Map() {};

template <typename Key, typename Value>
void Map<Key, Value>::Add(Key key, Value value)
{
    if (vec.size() == 0)
    {
        vec.push_back(make_pair(key, value));
    }
    else
    {
        auto res = find_if(vec.begin(), vec.end(), [&key](auto a) {return a.first == key; });
        if (res == vec.end())
        {
            vec.push_back(make_pair(key, value));
        }
        else
            cout << "Ключик " << '"' << key << '"' << " уже существует!" << endl;
    }
};

template <typename Key, typename Value>
void Map<Key, Value>::Print()
{
    for (auto const& pair : vec)
        cout << pair.first << " -> " << pair.second << endl;
};

template <typename Key, typename Value>
void Map<Key, Value>::Clear()
{
    vec.clear();
}

template <typename Key, typename Value>
Map<Key, Value>& Map<Key, Value>::operator=(Map<Key, Value> l)
{
    vec = l.vec;
    return *this;
};

template <typename Key, typename Value>
Value& Map<Key, Value>::operator[](Key key)
{
    auto found = find_if(vec.begin(), vec.end(), [&key](auto a) {return a.first == key; });
    if (found != vec.end())
    {
        return (*found).second;
    }
    vec.push_back(make_pair(key, Value()));
    return vec[vec.size() - 1].second;
};


void main() {
    setlocale(LC_ALL, "Russian");
    Map <string, int> h;
    Map <string, string> rom;
    Map <string, int> f;
    Map <string, string> pom;
    Map <string, string> Jake;
    Map <string, string> Kar;
#pragma region
    /*Kar.Add("ABC", "CBA");
    Jake.Add("ABC", "CBA");
    if (Kar == Jake)
    cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
    else
    cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;
    if (Kar != Jake)
    cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
    else
    cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;*/
    f.Add("kuku", 4);
    f.Add("kuku", 5);
    f.Add("sudo", 6);
    h = f;
    for (auto const& val : f)
    {
        std::cout << val.first << "  " << val.second << endl;
    }
    //cout << "--------------" << endl;
    //Jake.Add("joker", "Apple");
    //Jake.Add("kur", "trash");
    //pom = Jake;
    //pom.Print();
    //cout << "--------------" << endl;
    //pom.Remove("joker");
    //pom.Print();
    //cout << "--------------" << endl;
    //rom.Add("kost", "somtimes");
    //rom.Add("koster", "kolop");
    //rom.Add("molter", "getr");
    //h.Add("homka", "suxopuf");
    //h.Add("koplter", "Exode");
    //h.Print();
    //cout << "--------------" << endl;
    //h = rom;
    //h.Print();
    //cout << "----------------------" << endl;
    //
    //Kar.Print();
#pragma endregion   
    _getch();
}
