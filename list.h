#include <iostream>
#include <exception>

template <typename T>
class List {

public:
    List() { head = nullptr; };
    ~List() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    };

public:
    bool empty() const;
    void clear();
    void push_front(const T& value);
    void pop_front();
    void show();
    void erase_after(size_t);
    void insert_after(size_t, const T&);
    void reverse();
    void swap(List&);
    void sort();
    T& front() const;
private:
    struct Node {
        T useful_data;
        Node* next;
    };
    Node* head;
};

