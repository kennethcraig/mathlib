/*
mathlib - A basic foundation maths library 
Copyright (C) 2011 Kenneth C Andrews

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "vector2.h"
#include <math.h>

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
	m_x /= length();
	m_y /= length();
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
	return m_x != rhs.m_x && m_y != rhs.m_y;
}

Vector2& Vector2::operator= ( const Vector2& rhs )
{
	return *this = rhs;
}
