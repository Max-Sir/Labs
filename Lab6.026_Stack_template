#include <iostream>
using namespace std;
template <class T>
class Stack {
public:
    class Node {
    public:
        Node* under;
        T data;
        Node(T data, Node* top) {
            this->data = data;
            this->under = top;
            cout << "Data Node Constructed, data: " << data << endl;
        }
        ~Node() {
            cout << "Data Node Destructed, data: " << data << endl;
        }
    };
    Node* top = NULL;
    Stack() {

    }
    ~Stack() {
        while (top != NULL) {
            pop();
        }
    }
    void push(T data) {
        Node* newNode = new Node(data, top);
        top = newNode;
    }
    T pop() {
        Node* popped = top;
        T data = popped->data;
        top = top->under;
        delete popped;
        return data;
    }
};

template<>
class Stack<string>
{
public:
    class Node {
    public:
        Node* under;
        string data;
        Node(string data, Node* top) {
            this->data = data;
            this->under = top;
            cout << "Data Node Constructed, data: " << data << endl;
        }
        ~Node() {
            cout << "Data Node Destructed, data: " << data << endl;
        }
    };
    Node* top = NULL;
    Stack() {

    }
    ~Stack() {
        while (top != NULL) {
            pop();
        }
    }
    void push(string data) {
        Node* newNode = new Node(data, top);
        top = newNode;
    }
    string pop() {
        Node* popped = top;
        string data = popped->data;
        top = top->under;
        delete popped;
        return data;
    }
};

int main() {
	auto* s = new Stack<int>();//on the heap
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(8);
    s->push(9);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    delete s;
    Stack <string> s2;//on the stack
    s2.push("abceoj");
    s2.push("b");
    s2.push("c");
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    return 0;
}
