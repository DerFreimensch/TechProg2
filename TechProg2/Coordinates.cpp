#include "Coordinates.h"

Coordinates::Coordinates() {
    SetX(0);
    SetY(0);
    SetZ(0);
}
Coordinates::Coordinates(float x, float y, float z) {
    SetX(x);
    SetY(y);
    SetZ(z);
}
void Coordinates::operator++(int) {
    SetX(GetX() + 1.5f);
    SetY(GetY() + 1.5f);
    SetZ(GetZ() + 1.5f);
}
void Coordinates::operator--(int) {
    SetX(GetX() - 5.9f);
    SetY(GetY() - 5.9f);
    SetZ(GetZ() - 5.9f);
}
float Coordinates::operator++() {
    return (GetX() + GetY() + GetZ());
}
float Coordinates::operator--() {
    return (GetX() - GetY() - GetZ());
}
float Coordinates::GetX() {
    return X;
}
float Coordinates::GetY() {
    return Y;
}
float Coordinates::GetZ() {
    return Z;
}
void Coordinates::SetX(float X) {
    this->X = X;
}
void Coordinates::SetY(float Y) {
    this->Y = Y;
}
void Coordinates::SetZ(float Z) {
    this->Z = Z;
}