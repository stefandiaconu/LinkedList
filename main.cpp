#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Link
{
public:
    Link() : Next{nullptr} {};
    explicit Link(T value) : Value{value}, Next{nullptr} {};
    Link(T value, Link<T>* next) : Value{value}, Next{next} {};
    ~Link() = default;

    void SetValue(T v) { Value = v; }
    T GetValue() const { return Value; }

    Link<T>* Next;
private:
    T Value;
};

template <typename T>
class LinkedList
{
public:
    LinkedList() = default;

    void InsertBeginning(T item);
    void InsertEnd(T item);
    void DisplayList();
    int NumberOfItems();
    bool IsPresentItem(T item);
    void RemoveItem(T item);
    void Concat(LinkedList<T> list);
    void Copy(LinkedList<T> list);
    void InsertInOrder(T item);
    void Sort();

private:
    Link<T> *Head;
};

template<typename T>
void LinkedList<T>::InsertBeginning(T item) {
    Link<T>* newLink = new Link<T>();
    newLink->SetValue(item);
    newLink->Next = Head;
    Head = newLink;
}

template<typename T>
void LinkedList<T>::InsertEnd(T item) {
    Link<T>* temp;
    temp = Head;
    while (temp->Next != nullptr) {
        temp = temp->Next;
    }
    Link<T>* newLink = new Link<T>(item);
    temp->Next = newLink;
    newLink->Next = nullptr;
}

template<typename T>
void LinkedList<T>::DisplayList() {
    if (Head == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    Link<T>* temp;
    temp = Head;
    while (temp != nullptr) {
        std::cout << temp->GetValue() << std::endl;
        temp = temp->Next;
    }
}

template<typename T>
int LinkedList<T>::NumberOfItems() {
    int count = 0;
    if (Head == nullptr) {
        return count;
    }
    Link<T>* temp;
    temp = Head;
    while (temp != nullptr) {
        temp = temp->Next;
        count++;
    }
    return count;
}

template<typename T>
bool LinkedList<T>::IsPresentItem(T item) {
    Link<T>* temp;
    temp = Head;
    if (temp == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    while (temp != nullptr) {
        if (temp->GetValue() == item)
            return true;
        temp = temp->Next;
    }
    return false;
}

template<typename T>
void LinkedList<T>::RemoveItem(T item) {
    // TODO Handle removing head link
    Link<T>* temp;
    temp = Head;
    if (temp == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    if (temp->GetValue() == item) {
        Head = Head->Next;
    }
    else {
        while (temp != nullptr) {
            if (temp->Next != nullptr && temp->Next->GetValue() == item)
                temp->Next = temp->Next->Next;
            temp = temp->Next;
        }
    }
}

template<typename T>
void LinkedList<T>::Concat(LinkedList<T> list) {
    Link<T>* temp;
    temp = Head;
    if (temp == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    while (temp != nullptr) {
        if (temp->Next == nullptr) {
            temp->Next = list.Head;
            break;
        }
        temp = temp->Next;
    }
}

template<typename T>
void LinkedList<T>::Copy(LinkedList<T> list) {
    LinkedList<T> temp;
    temp.Head = Head;
    if (temp.Head == nullptr) {
        temp.Head = list.Head;
    }
    else {
        temp.Concat(list);
    }
}

template<typename T>
void LinkedList<T>::InsertInOrder(T item) {
    Link<T>* temp;
    temp = Head;
    if (temp == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    while (temp->Next != nullptr && temp->Next->GetValue() < item) {
        temp = temp->Next;
    }
    Link<T>* newLink = new Link<T>();
    newLink->Next = temp->Next;
    newLink->SetValue(item);
    temp->Next = newLink;
}

template<typename T>
void LinkedList<T>::Sort() {
    std::vector<T> tempVector;
    Link<T>* temp;
    temp = Head;
    if (temp == nullptr) {
        std::cout << "List if empty!" << std::endl;
    }
    while (temp != nullptr) {
        tempVector.push_back(temp->GetValue());
        temp = temp->Next;
    }
    std::sort(tempVector.begin(), tempVector.end());
    temp = Head;
    for (T& val : tempVector) {
        temp->SetValue(val);
        temp = temp->Next;
    }
}

int main() {

//    Link<int>* a = new Link<int>();
//    a->SetValue(3);
//    std::cout << a->GetValue() << std::endl;
//
//    Link<int> b{7};
//    std::cout << b.GetValue() << std::endl;
//
//    Link<int> c{8, a};
//    c.SetNext(&b);
//    c.SetNext(a);
//    std::cout << c.GetValue() << std::endl;
//    std::cout << c.GetNext().GetValue() << std::endl;

    LinkedList<int> list;
    std::cout << "Number of items: " << list.NumberOfItems() << std::endl;
    list.InsertBeginning(5);
    list.InsertBeginning(4);
    list.InsertBeginning(7);
    list.DisplayList();

    std::cout << "Before insert at the end" << std::endl;
    list.InsertEnd(9);
    list.DisplayList();

    std::cout << "Number of items: " << list.NumberOfItems() << std::endl;
    std::cout << "Is item " << 4 << " in the list? " << list.IsPresentItem(4) << std::endl;
    std::cout << "Is item " << 1 << " in the list? " << list.IsPresentItem(1) << std::endl;

    std::cout << "Before removing item!" << std::endl;
    list.RemoveItem(7);
    list.DisplayList();

    LinkedList<int> list2;
    list2.InsertBeginning(1);
    list2.InsertBeginning(2);
    list2.InsertBeginning(3);
    std::cout << "Display list2!" << std::endl;
    list2.DisplayList();
    std::cout << "Before concat!" << std::endl;
    list.Concat(list2);
    list.DisplayList();

    std::cout << "Before copy!" << std::endl;
    LinkedList<int> list3;
    list3.InsertBeginning(0);
    list3.InsertEnd(10);
    list3.Copy(list);
    list3.DisplayList();

    std::cout << "Before insert in order!" << std::endl;
    list3.InsertInOrder(8);
    list3.DisplayList();

    std::cout << "Before sorting!" << std::endl;
    list3.Sort();
    list3.DisplayList();

    return 0;
}
