// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef LAB5_LINKEDLIST_H
#define LAB5_LINKEDLIST_H
#include "func.h"
#include "matrix.h"
#include <iostream>
#include <stdexcept>
#include <vector>

class matrix {
public:

    int matrix_cols = 0;
    std::vector<int> matrix_data;
    //  LinkedList <T> matrix_data;

    void create_matrix();

//    void print_matrix();
    void transposing_matrix();
    void change_data();
    void change_one_element();
    void add_row();
    void delete_row();
    void add_col();
    void delete_col();

    friend std::ostream &operator<<(std::ostream &ostream, const matrix &matrix);
    friend std::istream &operator>>(std::istream &istream, matrix &matrix);
    matrix &operator=(const matrix &other);
    matrix operator+(const matrix &other) const;
    matrix operator-(const matrix &other) const;
    matrix &operator+=(int N);
    matrix &operator-=(int N);
    matrix &operator*=(int N);
    int operator==(const matrix &other) const;
};

template <typename T>
class LinkedList {
    static_assert(std::is_same_v<T, matrix>, "Only used matrix class type");
public:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size;


    LinkedList();
    ~LinkedList();

    void add(const T& value);
    void remove(int index);
    void print() const;
    T& get(int index);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
    template <typename U>
    friend std::istream& operator>>(std::istream& is, LinkedList<T>& list);

};

template <typename T>
T choise(LinkedList<T> list);
template <typename T>
T all_choise(LinkedList<T>& list);
template<typename T>
int find_index(LinkedList<T> list, const T& target);


template <typename U>
std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list) {
    os << "All list,\n";
    typename LinkedList<U>::Node* current = list.head;
    int i = 1;
    while (current != nullptr) {
        os << "(" << i << ") " << current->data << std::endl;
        current = current->next;
        i++;
    }
    return os;
}

template<typename U>
std::istream& operator>>(std::istream& is, LinkedList<U>& list) {
    U value;
    while (is >> value) {
        list.add(value);
    }
    return is;
}

template<typename T>
T &LinkedList<T>::get(int index){
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}


template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::add(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}


template <typename T>
void LinkedList<T>::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
T choise(LinkedList<T> list) {
    std::cout <<"\nEnter the number obj: " << list;
    int index = 0;
    int blin_temp = list.size;
    index = get_choize(1,blin_temp) - 1;
        return list.get(index);
}

template <typename T>
T all_choise(LinkedList<T>& list){
    std::cout<< "1 - to use an existing element, or 2 - to create a new one\n";
    int choize_wtf = get_choize(1, 2);

    if (choize_wtf == 1){
        return choise(list);
    } else{
        matrix nnnew;
        nnnew.create_matrix();
        list.add(nnnew);
        return nnnew;
    }
}

template<typename T>
int find_index(LinkedList<T> list, const T& target) {
    for (int i = 0; i < list.size + 1; i++) {
        if (list.get(i) == target) {
            return i;
        }
    }
}


#endif //LAB5_LINKEDLIST_H
