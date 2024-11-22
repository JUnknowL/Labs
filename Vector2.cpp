#include "Vector2.h"

std::ostream& operator<<(std::ostream& cout,Vector2 vec)
{
    cout<<"("<<vec.x<<","<<vec.y<<")";
    return cout;
}
inline Vector2& operator/(float f, Vector2& vec)
{
    vec.x/=f;
    vec.y/=f;
    return vec;
}
inline Vector2& operator*(float f, Vector2& vec)
{
    vec.x*=f;
    vec.y*=f;
    return vec;
}
inline Vector2& Vector2::operator*=(float f)
{
    x*=f;
    y*=f;
    return *this;
}
inline Vector2& Vector2::operator/=(float f)
{
    x/=f;
    y/=f;
    return *this;
}
inline float& Vector2::operator[](int i)
{
    switch (i)
    {
    case 0:
        return x;
        break;
    case 1:
        return y;
        break;
    default:
        assert(false);
        break;
    }
}
inline Vector2& Vector2::operator+=(float f)
{
    x+=f;
    y+=f;
    return *this;
}
inline Vector2& Vector2::operator-=(float f)
{
    x-=f;
    y-=f;
    return *this;
}
inline Vector2 Vector2::operator+(Vector2 vec)
{
    return {x+vec.x,y+vec.y};
}
inline Vector2 Vector2::operator-(Vector2 vec)
{
    return {x-vec.x,y-vec.y};
}
inline Vector2& Vector2::operator*(float f)
{
    x*=f;
    y*=f;
    return *this;
}
inline Vector2& Vector2::operator/(float f)
{
    x/=f;
    y/=f;
    return *this;
}