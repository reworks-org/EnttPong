///
/// AI.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_COMPONENTS_AI_HPP_
#define ENTTPONG_COMPONENTS_AI_HPP_

namespace ep
{
	///
	/// Keeps track of the AI's movement.
	///
	class AI final
	{
	public:
		///
		/// Argument Constructor.
		///
		/// \param x The starting x-pos on screen.
		/// \param y The starting y-pos on screen.
		///
		AI(const double x, const double y) noexcept;

		///
		/// Move constructor.
		///
		AI(AI&&) noexcept;

		///
		/// Default destructor.
		///
		~AI() noexcept = default;

		///
		/// Move assignment overload.
		///
		AI& operator=(AI&&) noexcept;

	public:
		///
		/// x pos on screen.
		///
		double m_x;

		///
		/// y pos on screen.
		///
		double m_y;
	};
} // namespace ep

#endif