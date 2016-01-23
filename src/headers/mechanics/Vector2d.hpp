#ifndef __IDEAL_GAS_TOGETHER_VECTOR2D_HPP__
#define __IDEAL_GAS_TOGETHER_VECTOR2D_HPP__

//----------------------------------------------------------------------------
//{ Includes
//----------------------------------------------------------------------------

	#include <cstdlib> 
    #include <math.h>

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Vector2d
//----------------------------------------------------------------------------

	struct Vector2d
	{
		public:

			// Constructor:

				Vector2d(double newX, double newY);

			// Functions:

				// Debugging:

					inline void print() const;

				// Length:

					inline double length() const;

				// Normalization:

					inline Vector2d& normalize();
					inline Vector2d  normalized() const;

			// Operators:

				inline Vector2d& operator+=(const Vector2d& vector);
				inline Vector2d& operator-=(const Vector2d& vector);
				inline Vector2d& operator*=(double koefficient);
				inline Vector2d& operator/=(double koefficient);

			// Variables:

				double x, y;
	};

	//----------------------------------------------------------------------------
	//{ Constructor
	//----------------------------------------------------------------------------

		Vector2d::Vector2d(double newX, double newY) :
			x (newX),
			y (newY)
		{}

	//}
	//----------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------
	//{ Functions
	//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		//{ Debugging
		//----------------------------------------------------------------------------

			inline void Vector2d::print() const
			{
				printf("(%7.04f %7.04f)", x, y);
			}

		//}
		//----------------------------------------------------------------------------


		//----------------------------------------------------------------------------
		//{ Length
		//----------------------------------------------------------------------------

			inline double Vector2d::length() const
			{
				return sqrt(x * x + y * y);
			}

		//}
		//----------------------------------------------------------------------------


		//----------------------------------------------------------------------------
		//{ Normalization
		//----------------------------------------------------------------------------

			inline Vector2d& Vector2d::normalize()
			{
				double len = length();

				if (abs(len) < 0.0001f) len = 0.0001f;

				x /= len;
				y /= len;

				return *this;
			}

			inline Vector2d Vector2d::normalized() const
			{
				Vector2d toReturn = *this;

				toReturn.normalize();

				return toReturn;
			}

		//}
		//----------------------------------------------------------------------------
		
	//}
	//----------------------------------------------------------------------------


	//----------------------------------------------------------------------------
	//{ Operators
	//----------------------------------------------------------------------------

		// Arithmetics:

			inline Vector2d& Vector2d::operator+=(const Vector2d& vector)
			{
				x += vector.x;
				y += vector.y;
					
				return *this;
			}

			inline Vector2d& Vector2d::operator-=(const Vector2d& vector)
			{
				x -= vector.x;
				y -= vector.y;
					
				return *this;
			}

			inline Vector2d& Vector2d::operator*=(double koefficient)
			{
				x *= koefficient;
				y *= koefficient;
					
				return *this;
			}

			inline Vector2d& Vector2d::operator/=(double koefficient)
			{
				if (abs(koefficient) < 0.0001f) koefficient = 0.0001;

				x /= koefficient;
				y /= koefficient;
					
				return *this;
			}

	//}
	//----------------------------------------------------------------------------


	//----------------------------------------------------------------------------
	//{ Related functions
	//----------------------------------------------------------------------------

		// Vector arithmetics:

			inline Vector2d operator+(const Vector2d& vector0, const Vector2d& vector1)
			{
				Vector2d toReturn = vector0;

				toReturn += vector1;

				return toReturn;
			}

			inline Vector2d operator-(const Vector2d& vector0, const Vector2d& vector1)
			{
				Vector2d toReturn = vector0;

				toReturn -= vector1;

				return toReturn;
			}

			inline Vector2d operator*(const Vector2d& vector0, double koefficient)
			{
				Vector2d toReturn = vector0;

				toReturn *= koefficient;

				return toReturn;
			}

			inline Vector2d operator/(const Vector2d& vector0, double koefficient)
			{
				Vector2d toReturn = vector0;

				toReturn /= koefficient;

				return toReturn;
			}

		// Dot product:

			inline double operator*(const Vector2d& vector0, const Vector2d& vector1)
			{
				return vector0.x * vector1.x + vector0.y * vector1.y;
			}

	//}
	//----------------------------------------------------------------------------

//}
//----------------------------------------------------------------------------

#endif /*__IDEAL_GAS_TOGETHER_VECTOR2D_HPP__*/