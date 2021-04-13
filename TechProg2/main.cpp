#include <iostream>
#include "Coordinates.h"
#include "Stack.h"
void TestCoord();
void TestStack(int l);
void Adding(Stack& A);
void ShowQueue(Stack& A);
void Menu();
int main() {
    Menu();
    return 0;
}
void Adding(Stack& A) {
    int Number;
    for (int i = 0; i < A.GetLength(); i++) {
        std::cout << "Print element number " << (i + 1) << std::endl;
        std::cin >> Number;
        A.AddNode(Number);
    }
}
void TestStack(int l) {
    int NumberOfNodes;
    std::cout << "print number of nodes in first stack" << std::endl;
    std::cin >> NumberOfNodes;
    Stack First(NumberOfNodes);
    Adding(First);
    std::cout << "print number of nodes in second stack" << std::endl;
    std::cin >> NumberOfNodes;
    Stack Second(NumberOfNodes);
    Adding(Second);
    std::cout << (First == Second) << std::endl;
    std::cout << (First != Second) << std::endl;
    std::cout << (First <= Second) << std::endl;
    std::cout << (First > Second) << std::endl;
    std::cout << (First >= Second) << std::endl;
    std::cout << (First < Second) << std::endl;
    ShowQueue(*First(l));
    ShowQueue(*Second(l));

}
void Menu() {
    int choose;
    std::cout << "Menu" << std::endl;
    std::cout << "1) Testing Stack" << std::endl;
    std::cout << "2) Testing Coordinates" << std::endl;
    std::cout << "3) Back to make Stacks" << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cin >> choose;
    if (choose != 1 && choose != 2 && choose != 0) {
        std::cout << "Wrong option, try again" << std::endl;
        Menu();
    }
    switch (choose) {
    case 1: {
        int l;
        std::cout << "print length of Under Stack" << std::endl;
        std::cin >> l;
        TestStack(l);
        Menu();
    }
    case 2:
        TestCoord();
        Menu();
    case 0:
        exit(0);
    }
}

void TestCoord() {
    float X, Y, Z;
    std::cout << "print Coordinates" << std::endl;
    std::cin >> X;
    std::cin >> Y;
    std::cin >> Z;
    Coordinates* A = new Coordinates(X, Y, Z);
    std::cout << "[" << A->GetX() << ";" << A->GetY() << ";" << A->GetZ() << "]" << std::endl;
    (*A)++;
    std::cout << "[" << A->GetX() << ";" << A->GetY() << ";" << A->GetZ() << "]" << std::endl;
    (*A)--;
    std::cout << "[" << A->GetX() << ";" << A->GetY() << ";" << A->GetZ() << "]" << std::endl;
    std::cout << ++(*A) << std::endl;
    std::cout << "[" << A->GetX() << ";" << A->GetY() << ";" << A->GetZ() << "]" << std::endl;
    std::cout << --(*A) << std::endl;
    std::cout << "[" << A->GetX() << ";" << A->GetY() << ";" << A->GetZ() << "]" << std::endl;
}

void ShowQueue(Stack& A) {
    Node* Now = A.GetLast();
    if (A.GetLast() == nullptr) {
        std::cout << "Queue is Empty" << std::endl;
    }
    else {
        std::cout << Now->Number << " ";
        while (Now->NextPtr != nullptr) {
            Now = Now->NextPtr;
            std::cout << Now->Number << " ";
        }
        std::cout << std::endl;
    }
}