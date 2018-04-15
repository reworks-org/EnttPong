///
/// AITag.hpp
/// EnttPong
///
/// MIT LICENSE.
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_AITAG_HPP_
#define ENTTPONG_AITAG_HPP_

namespace ep
{
	///
	/// Literally an identifier class.
	/// Used to retrieve AI entity.
	///
	class AITag final
	{
	public:
		///
		/// Main Constructor.
		///
		///
		AITag() = default;

		///
		/// Default destructor.
		///
		~AITag() = default;

		///
		/// Move assignment overload.
		///
		AITag& operator=(const AITag &) noexcept;
	};
}

#endif