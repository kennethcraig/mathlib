/*
mathlib - A basic foundation maths library 

The following library is hereby released under the CC0 License, a copy of which can be found at 

http://creativecommons.org/publicdomain/zero/1.0/legalcode
*/

#include <math.h>
#include <ostream>

#include "vector3.h"

Vector3 Vector3::X = Vector3( 1.0, 0.0, 0.0 );
Vector3 Vector3::Y = Vector3( 0.0, 1.0, 0.0 );
Vector3 Vector3::Z = Vector3( 0.0, 0.0, 1.0 );

Vector3::Vector3()
 : m_x( 0.0 )
 , m_y( 0.0 )
 , m_z( 0.0 )
{

}

Vector3::Vector3( double x, double y, double z )
 : m_x( x )
 , m_y( y )
 , m_z( z )
{
	
}

Vector3::Vector3( const Vector3& rhs )
 : m_x( rhs.m_x )
 , m_y( rhs.m_y )
 , m_z( rhs.m_z ) 
{
	
}

double Vector3::x() const
{
	return m_x;
}

double Vector3::y() const
{
	return m_y;
}

double Vector3::z() const
{
	return m_z;
}

void Vector3::normalise()
{
	double len = length();
	m_x /= len;
	m_y /= len;
	m_z /= len;
}

Vector3 Vector3::getNormalised() const
{	
	Vector3 tmp(*this);
	tmp.normalise();
	return tmp;
}

double Vector3::dot( const Vector3& rhs ) const
{
	return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z;
}

Vector3 Vector3::cross( const Vector3& rhs ) const
{
	return (((this->m_y * rhs.m_z) - (this->m_z * rhs.m_y)) * Vector3::X) + 
		(((this->m_z * rhs.m_x) - (this->m_x * rhs.m_z)) * Vector3::Y) + 
		(((this->m_x * rhs.m_y) - (this->m_y * rhs.m_x)) * Vector3::Z);
}

double Vector3::length() const
{
	return sqrt( dot(*this ) );
}

const Vector3 Vector3::operator+ ( const Vector3& rhs ) const
{
	return Vector3( m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z );
}

const Vector3 Vector3::operator- ( const Vector3& rhs ) const
{
	return Vector3( m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z );
}

const Vector3 Vector3::operator- () const
{
	return Vector3( 0 - m_x, 0 - m_y, 0 - m_z );
}

const Vector3 Vector3::operator* ( const Vector3& rhs ) const
{
	return Vector3( m_x * rhs.m_x, m_y * rhs.m_y, m_z * rhs.m_z );
}

const Vector3 Vector3::operator* ( double rhs ) const
{
	return Vector3( m_x * rhs, m_y * rhs, m_z * rhs );
}

Vector3& Vector3::operator+= ( const Vector3& rhs )
{
	*this = *this + rhs;
	return *this;
}

Vector3& Vector3::operator-= ( const Vector3& rhs )
{
	*this = *this - rhs;
	return *this;
}


Vector3& Vector3::operator*= ( const Vector3& rhs )
{
	*this = *this * rhs;
	return *this;

}

Vector3& Vector3::operator*= ( double rhs )
{
	*this = *this * rhs;
	return *this;
}

bool Vector3::operator== ( const Vector3& rhs ) const
{
	return m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z;
}

bool Vector3::operator!= ( const Vector3& rhs ) const
{
	return m_x != rhs.m_x || m_y != rhs.m_y || m_z != rhs.m_z;
}

Vector3& Vector3::operator= ( const Vector3& rhs )
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	m_z = rhs.m_z;
	return *this;
}

const Vector3 operator* ( double lhs, const Vector3& rhs )
{
	return rhs * lhs;
}

std::ostream& operator<< ( std::ostream& os, const Vector3& rhs )
{
	return os << "{" << rhs.m_x << "," << rhs.m_y << "," << rhs.m_z << "}";
}
