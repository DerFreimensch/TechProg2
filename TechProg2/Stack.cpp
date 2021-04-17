#include "Stack.h"
Stack::Stack(int A) {
    SetLength(A);
    SetLast(nullptr);
}
Stack::~Stack() {
    SetLast(nullptr);
}

Stack::Stack(const Stack& St2) {
    this->SetLength(St2.length);
    this->Recursion(St2.Last);
    this->AddNode(St2.Last->Number);
}
void Stack::Recursion(Node* ptr) {
    if (ptr->NextPtr != nullptr) {
        ptr = ptr->NextPtr;
        Recursion(ptr);
        this->AddNode(ptr->Number);
    }
    
}
bool Stack::operator==(Stack &St2) {
    Node* Now1 = this->GetLast();
    Node* Now2 = St2.GetLast();
    if (this->GetLength() == St2.GetLength()) {
        while (Now1->Number == Now2->Number) {
            Now1 = Now1->NextPtr;
            Now2 = Now2->NextPtr;
            if (Now1 == nullptr) {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool Stack::operator !=(Stack &St2) {
    return !(*this == St2);
}
bool Stack::operator<(Stack &St2) {
    Node* Now1 = this->GetLast();
    Node* Now2 = St2.GetLast();
    if (this->GetLength() == St2.GetLength()) {
        while (Now1->Number < Now2->Number) {
            Now1 = Now1->NextPtr;
            Now2 = Now2->NextPtr;
            if (Now1 == nullptr) {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool Stack::operator >=(Stack &St2) {
    return !(*this < St2);
}
bool Stack::operator>(Stack &St2) {
    Node* Now1 = this->GetLast();
    Node* Now2 = St2.GetLast();
    if (this->GetLength() == St2.GetLength()) {
        while (Now1->Number > Now2->Number) {
            Now1 = Now1->NextPtr;
            Now2 = Now2->NextPtr;
            if (Now1 == nullptr) {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool Stack::operator <=(Stack &St2) {
    return !(*this < St2);
}
Stack* Stack::operator()(int L) {
    Node* Now = GetLast();
    Stack* Under = new Stack(this->GetLength());
    for (int i = 0; i < L; i++) {
        Under->AddNode(Now->Number);
        Now = Now->NextPtr;
    }
    return Under;
}



void Stack::AddNode(int Numbers) {
    Node* NodePtrIt = new Node;
    NodePtrIt->Number = Numbers;
    if (nullptr == GetLast()) {
        SetLast(NodePtrIt);
        NodePtrIt->NextPtr = nullptr;
    }
    else {
        NodePtrIt->NextPtr = GetLast();
        SetLast(NodePtrIt);
    }
}


void Stack::SetLength(int a) {
    this->length = a;
}
int Stack::GetLength() {
    return this->length;
}
void Stack::SetLast(Node* NewLast) {
    this->Last = NewLast;
}
Node* Stack::GetLast() {
    return this->Last;
}
bool Stack::isEmpty() {
    if (GetLast() == nullptr) {
        return false;
    }
    else {
        return true;
    }
}