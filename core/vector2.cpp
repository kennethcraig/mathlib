/*
mathlib - A basic foundation maths library 

The following library is hereby released under the CC0 License, a copy of which can be found at 

http://creativecommons.org/publicdomain/zero/1.0/legalcode
*/

#include <math.h>

#include "vector2.h"

Vector2 Vector2::X = Vector2( 1.0, 0.0 );
Vector2 Vector2::Y = Vector2( 0.0, 1.0 );

Vector2::Vector2()
 : m_x( 0 )
 , m_y( 0 )
{
}

Vector2::Vector2( double x, double y )
 : m_x( x )
 , m_y( y )
{

}

Vector2::Vector2( const Vector2& rhs )
 : m_x ( rhs.m_x )
 , m_y ( rhs.m_y )
{

}

double Vector2::x() const
{
	return m_x;
}

double Vector2::y() const
{
	return m_y;
}

void Vector2::normalise()
{
	double len = length();
	m_x /= len;
	m_y /= len;
}

Vector2 Vector2::getNormalised() const
{
	Vector2 tmp(*this);
	tmp.normalise();
	return tmp;
}

double Vector2::dot( const Vector2& rhs ) const
{
	return m_x * rhs.m_x + m_y * rhs.m_y;
}

double Vector2::length() const
{
	return sqrt(dot(*this));
}

const Vector2 Vector2::operator+ ( const Vector2& rhs ) const
{
	return Vector2( m_x + rhs.m_x, m_y + rhs.m_y );
}

const Vector2 Vector2::operator- ( const Vector2& rhs ) const
{
	return Vector2( m_x - rhs.m_x, m_y - rhs.m_y );
}

const Vector2 Vector2::operator- () const
{
	return Vector2( 0 - m_x, 0 - m_y );
}

const Vector2 Vector2::operator* ( const Vector2& rhs ) const
{
	return Vector2( m_x * rhs.m_x, m_y * rhs.m_y );
}

const Vector2 Vector2::operator* ( double rhs ) const
{
	return Vector2( m_x * rhs, m_y * rhs );
}

Vector2& Vector2::operator+= ( const Vector2& rhs )
{
	m_x += rhs.m_x;
	m_y += rhs.m_y;
	return *this;
}

Vector2& Vector2::operator-= ( const Vector2& rhs )
{
	m_x -= rhs.m_x;
	m_y -= rhs.m_y;
	return *this;
}


Vector2& Vector2::operator*= ( const Vector2& rhs )
{
	m_x *= rhs.m_x;
	m_y *= rhs.m_y;
	return *this;
}

Vector2& Vector2::operator*= ( double rhs )
{
	m_x *= rhs;
	m_y *= rhs;
	return *this;
}

bool Vector2::operator== ( const Vector2& rhs ) const
{
	return m_x == rhs.m_x && m_y == rhs.m_y;
}

bool Vector2::operator!= ( const Vector2& rhs ) const
{
	return m_x != rhs.m_x || m_y != rhs.m_y;
}

Vector2& Vector2::operator= ( const Vector2& rhs )
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	return *this;
}

const Vector2 operator* ( double lhs, const Vector2& rhs )
{
	return rhs * lhs;
}

std::ostream& operator<< ( std::ostream& os, const Vector2& rhs )
{
	return os << "{" << rhs.m_x << "," << rhs.m_y << "}";
}
