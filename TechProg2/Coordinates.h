#pragma once
class Coordinates {
private:
    float X;
    float Y;
    float Z;
public:
    Coordinates();
    Coordinates(float x, float y, float z);
    void operator ++ (int);
    void operator -- (int);
    float operator ++ ();
    float operator -- ();
    float GetX();
    float GetY();
    float GetZ();
    void SetX(float X);
    void SetY(float Y);
    void SetZ(float Z);
};
