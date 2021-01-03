///
/// Ball.hpp
/// EnttPong
///
/// Refer to LICENSE.txt for more details.
///

#ifndef ENTTPONG_COMPONENTS_BALL_HPP_
#define ENTTPONG_COMPONENTS_BALL_HPP_

namespace ep
{
	///
	/// Makes an entity a ball.
	///
	class Ball final
	{
	public:
		///
		/// Arg Constructor.
		///
		/// \param vel_x Initial X Velocity.
		/// \param vel_y Initial Y Velocity.
		///
		Ball(const double vel_x, const double vel_y) noexcept;

		///
		/// Move constructor.
		///
		Ball(Ball&&) noexcept;

		///
		/// Default destructor.
		///
		~Ball() noexcept = default;

		///
		/// Move assignment overload.
		///
		Ball& operator=(Ball&&) noexcept;

		///
		/// Get initial x velocity.
		///
		/// \return Const double.
		///
		[[nodiscard]] const double initial_x_vel() const noexcept;

		///
		/// Get initial x velocity.
		///
		/// \return Const double.
		///
		[[nodiscard]] const double initial_y_vel() const noexcept;

	public:
		///
		/// The X velocity of the ball.
		///
		double m_vel_x;

		///
		/// The Y velocity of the ball.
		///
		double m_vel_y;

		///
		/// The number of ticks the ball is bounce immune for
		///
		int m_bounce_immune_ticks;

	private:
		///
		/// The original X velocity of the ball.
		///
		double m_initial_vel_x;

		///
		/// The original Y velocity of the ball.
		///
		double m_initial_vel_y;
	};
} // namespace ep

#endif