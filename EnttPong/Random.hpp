///
/// Random.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_RANDOM_HPP_
#define ENTTPONG_RANDOM_HPP_

#include <random>

namespace ep
{
	///
	/// Credits: http://stackoverflow.com/a/32907541.
	///
	template<typename Type>
	using conditional_distribution = std::conditional_t<
	    std::is_integral<Type>::value,
	    std::uniform_int_distribution<Type>,
	    std::conditional_t<std::is_floating_point<Type>::value, std::uniform_real_distribution<Type>, void>>;

	///
	/// Generate a random integer.
	///
	/// \param min Minimum number inclusive.
	/// \param max Maximum number inclusive.
	///
	/// \return Returns number between min-max, inclusive.
	///
	[[nodiscard]] inline int random(const int min, const int max)
	{
		std::random_device rd;
		std::mt19937_64 mt {rd()};

		conditional_distribution<int> dist {min, max};

		return dist(mt);
	}
} // namespace ep

#endif