#include "list.h"

template <typename T>
bool List<T>::empty() const {
    return head == nullptr;
}

template <typename T>
void List<T>::clear() {
    if (head) {
        return;
    }
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node* tmp = new Node();
    tmp->useful_data = value;
    tmp->next = head;
    head = tmp;
}

template <typename T>
void List<T>::pop_front() {
    if(empty()) {
        throw std::logic_error(" List is empty ");
    }
    else {
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

template <typename T>
void List<T>::show() {
    Node* tmp = head;
    while (tmp) {
        std::cout << tmp->useful_data << std::endl;
        tmp = tmp->next;
    }
}

template <typename T>
void List<T>::insert_after(size_t index, const T& value) {

    if (empty()) {
        throw std::logic_error(" List is empty ");
    }
    else if (0 == index) {
        push_front(value);
    }
    else {
        Node* temp  = new Node();
        Node* ptr = head;
        Node* temp1 = head;

        for (size_t i = 0; i < index + 1; ++i) {
            ptr = ptr->next;
        }
        for (size_t i = 0; i < index; ++i) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = ptr;
        temp->useful_data = value;
    }
}

template <typename T>
void List<T>::erase_after(size_t index) {
    if (empty()) {
        throw std::logic_error(" List is empty ");
    }
    else if (0 == index) {
        pop_front();
    }
    else {
        size_t count = 0;
        Node* tmp = head;
        while (tmp->next) {
            ++count;
            if (count == index) {
                Node* tmp1 = tmp->next->next;
                delete tmp->next;
                tmp->next = tmp1;
            }
            else {
                tmp = tmp->next;
            }

        }
    }
}

template <typename T>
void List<T>::reverse() {
    if (empty()) {
        throw std::logic_error(" List is empty ");
    }
    Node* cur = head;
    Node* prev = nullptr;

    while (cur != nullptr) {
        Node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    head = prev;
}

template <typename T>
T& List<T>::front() const {
    if (empty()) {
        throw std::logic_error(" List is empty ");
    }
    return head->useful_data;
}

template <typename T>
void List<T>::sort() {
    for (Node* cur = head; cur->next != nullptr; cur = cur->next) {
        for (Node* cur1 =         cur->next; cur1 != nullptr; cur1 = cur1->next) {
            if (cur->useful_data > cur1->useful_data) {
                std::swap(cur->useful_data, cur1->useful_data);
            }
        }
    }
}

template <typename T>
void List<T>::swap(List& list1) {
    std::swap(this->head, list1.head);
}


int main() {
    //List<int> obj;
    //std::cout << std::boolalpha << obj.empty() << std::endl;
    //obj.clear();
    //obj.push_front(99);
    //obj.push_front(28);
    //obj.push_front(77);
    //obj.push_front(7);
    //obj.show();
    //obj.pop_front();
    //obj.insert_after(1, 100);
    //std::cout << std::endl;
    //obj.show();
    //obj.erase_after(2);
    //obj.reverse();
    //obj.sort();
    //std::cout << std::endl;
    //obj.show();
    //std::cout << obj.front() << std::endl;
    //List<int> obj1;
    //obj1.push_front(9);
    //obj1.push_front(54);
    //obj1.push_front(1);
    //obj1.push_front(75);
    //obj.swap(obj1);
    //std::cout << std::endl;
    //obj.show();
}
