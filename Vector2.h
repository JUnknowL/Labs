#pragma once
#include <assert.h>
#include <iostream>

struct Vector2
{
    float x;
    float y;

    inline Vector2& operator*=(float f);
    inline Vector2& operator/=(float f);
    inline Vector2 operator+(Vector2 vec);
    inline Vector2 operator-(Vector2 vec);
    inline Vector2& operator+=(float f);
    inline Vector2& operator-=(float f);
    inline float& operator[](int i);
    inline Vector2& operator*(float f);
    inline Vector2& operator/(float f);
};

inline Vector2& operator*(float f, Vector2& vec);
inline Vector2& operator/(float f, Vector2& vec);
std::ostream& operator<<(std::ostream& cout,Vector2 vec);