// lab 7-9.1-26.cpp : This file contains the 'main' function. Program execution begins and ends there
#include <ctime>
#include <iostream>
#include<string>
#include <exception>

using namespace std;

namespace lab7
{
	template<class K, class V>
	struct pair;
	template<class K,class V>
	class Dict;
	template<class K, class V>
	struct Node;
	class Exception;
	template<class K, class V>
	class Iterator;
	void unexpected_handler();

	void terminate_handler();
}

using lab7::Exception;
void lab7::unexpected_handler()
{
	std::cerr << "Unexpected exception\n";
	std::terminate();
}

void lab7::terminate_handler()
{
	std::cerr << "terminate called\n";
	abort();
}

template<class K, class V>
struct lab7::pair {
	K key;
	V value;
};
using lab7::pair;
template<class K, class V>
struct lab7::Node
{
public:
	pair<K, V> data;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node(K key, V value)
	{
		this->data.key = key;
		this->data.value = value;
	}
	void set_value(V value)
	{
		this->data.value = value;
	}
	void set_key(K key)
	{
		this->data.key = key;
	}

	/*V& second()
	{
		return this->value;
	}*/


	ostream& operator<<(ostream& o)
	{
		o << data.key << " : " << data.value;
		return o;
	}
};

template<class K,class V>
class lab7::Dict
{
	Node<K,V>* begin = nullptr;
	Node<K,V>* tail = nullptr;
public:
	template<class K, class V>
	friend class lab7::Iterator;
	
	
	void push(K key,V value)
	{
		if(is_empty())
		{
			data = tail = new Node<K,V>(key, value);
		}
		else if(!contains(key))
		{
			auto tmp = new Node<K,V>(key,value);
			tail->next = tmp;
			tail = tmp;
		}
	}

	void del_by_key(K key)
	{
		for(auto it : this)
		{
			
		}
	}

	V& operator[](const K& key)
	{
		extern V val_ret;
		val_ret=find(key).value;//except ++++++++
		
	}

	Node<K,V>& find(K key)//???????
	{
		Node<K, V> ret_node=nullptr;
		try
		{
			if (is_empty()) throw "Container is Empty\n";
			for(auto i:data)
		{
				if (i.key == key)
				{
					ret_node = i;
				}
		}
		}
		catch (string& ex) { cerr << ex; }
		try {
			if (!ret_node) throw "No such element!!!";
			return ret_node;
		}
		catch (string& ex)
		{
			cerr << ex;
		}
		return nullptr;
	}
	
	bool is_empty()
	{
		return !data;
	}

	void show()
	{
		for(auto i:data)
		{
			cout << *i << " ";
		}
	}
	
	bool contains(K key)
	{
		bool fl = false;
		for(auto i:data)
		{
			if(i.key==key)
			{
				fl = true;
				break;
			}
		}
		return fl;
	}
	
};

class lab7::Exception
{
public:
	Exception(const std::string errorMessage = "Something wrong") : m_ErrorMessage(errorMessage) { }
	friend std::ostream& operator<< (std::ostream& out, const Exception& ex) { out << ex.m_ErrorMessage << '\n'; return out; }
private:
	std::string m_ErrorMessage;
};

template<class K, class V>
class lab7::Iterator
{
public:
	friend class lab7::Dict<K,V>;
	Iterator(lab7::Node<K,V>* node = nullptr) : node(node) { }
	~Iterator() { }
	Iterator(const Iterator& it) { node = it.node; }
	inline Iterator& operator=(const Iterator& it) { node = it.node; return *this; }
	inline K& operator*() { if (node == nullptr) throw Exception("Empty iterator"); return node->data; }
	inline K* operator->() { if (node == nullptr) throw Exception("Empty iterator"); return &node->data; }
	inline Iterator& operator++() { if (node == nullptr) throw Exception("Empty iterator"); node = node->next; return *this; }
	//inline Iterator& operator--() { if (node == nullptr) throw Exception("Empty iterator"); node = node->prev; return *this; }
	inline Iterator operator++(int unused) { if (node == nullptr) throw Exception("Empty iterator"); Iterator res = *this; node = node->next; return res; }
	//inline Iterator operator--(int unused) { if (node == nullptr) throw Exception("Empty iterator"); Iterator res = *this; node = node->prev; return res; }
	inline bool operator== (const Iterator& it) { return node == it.node; }
	inline bool operator!= (const Iterator& it) { return node != it.node; }
	inline ostream& operator<<(ostream& o) { if (node == nullptr) throw Exception("Empty iterator"); cout << *this; }
private:
	lab7::Node<K,V>* node;
};


int main()
{
	srand(time(nullptr));
	std::set_terminate(lab7::terminate_handler);
	std::set_unexpected(lab7::unexpected_handler);
	return 0;
}
