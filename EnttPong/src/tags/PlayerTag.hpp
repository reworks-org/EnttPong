///
/// PlayerTag.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_PLAYERTAG_HPP_
#define ENTTPONG_PLAYERTAG_HPP_

namespace ep
{
	///
	/// Literally an identifier class.
	/// Used to retrieve player entity.
	///
	class PlayerTag final
	{
	public:
		///
		/// Main Constructor.
		///
		///
		PlayerTag() = default;

		///
		/// Default destructor.
		///
		~PlayerTag() = default;

		///
		/// Move assignment overload.
		///
		PlayerTag& operator=(const PlayerTag &);
	};
}

#endif