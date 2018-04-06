///
/// RandomVelocity.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#include <random>

namespace ep
{
	///
	/// \brief Randomizes velocity sign.
	///
	/// Lets the ball bounce in a random direction.
	/// Yay for stack overflow.
	/// https://stackoverflow.com/a/7560564
	///
	/// \param velocity Velocity to use
	/// 
	/// \return double Neg or Pos 0.12.
	///
	inline double randomVelocitySign(double velocity)
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 eng(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, 1); // define the range

		if (distr(eng) != 0)
		{
			return (-velocity);
		}
		else
		{
			return (velocity);
		}
	}
}