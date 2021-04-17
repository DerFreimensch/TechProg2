#pragma once
class Node {
public:
    int Number;
    Node* NextPtr;
};
class Stack {
private:
    int length;
    Node* Last;
public:
    Stack(int A);
    Stack(const Stack& St2);
    ~Stack();
    void Recursion(Node *ptr);
    void AddNode(int Numbers);
    bool operator != (Stack &St2);
    bool operator == (Stack &St2);
    bool operator < (Stack &St2);
    bool operator >= (Stack &St2);
    bool operator > (Stack &St2);
    bool operator <= (Stack &St2);
    Stack* operator ()(int L);
    bool isEmpty();

    void SetLength(int a);
    int GetLength();
    void SetLast(Node* NewLast);
    Node* GetLast();

};