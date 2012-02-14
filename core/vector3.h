/*
mathlib - A basic foundation maths library 

The following library is hereby released under the CC0 License, a copy of which can be found at 

http://creativecommons.org/publicdomain/zero/1.0/legalcode
*/

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Vector3
{
public:
	Vector3();
	Vector3( double x, double y, double z );
	Vector3( const Vector3& rhs );
	
	double x() const;
	double y() const;
	double z() const;
	
	void normalise();
	Vector3 getNormalised() const;
	
	double dot( const Vector3& rhs ) const;
	
	Vector3 cross( const Vector3& rhs ) const;
	
	double length() const;
	
	const Vector3 operator+ ( const Vector3& rhs ) const;
	const Vector3 operator- ( const Vector3& rhs ) const;
	const Vector3 operator- () const;
	const Vector3 operator* ( const Vector3& rhs ) const;
	const Vector3 operator* ( double rhs ) const;
	
	Vector3& operator+= ( const Vector3& rhs );
	Vector3& operator-= ( const Vector3& rhs );
	Vector3& operator*= ( const Vector3& rhs );
	Vector3& operator*= ( double rhs );
	
	bool operator== ( const Vector3& rhs ) const;
	bool operator!= ( const Vector3& rhs ) const;
	
	Vector3& operator= ( const Vector3& rhs );
		
	friend std::ostream& operator<< ( std::ostream& os, const Vector3& rhs );

	// standard basis vectors, also known as i,j & k respectively.
	static Vector3 X;
	static Vector3 Y;
	static Vector3 Z;
	
private:

	double m_x;
	double m_y;
	double m_z;
};

const Vector3 operator* ( double lhs, const Vector3& rhs );

#endif // _VECTOR3_H_

