//
// Created by whitemaks on 14.11.2026.
//

#pragma once

#include <array>
#include <cstdint>

#include <engine/input/ButtonState.h>

namespace input {
	enum class MouseButton : std::uint8_t
	{
		Unknown = 0,

		Left,
		Right,
		Middle,

		Button4,
		Button5,
		Button6,
		Button7,
		Button8,

		Count
	};

	//todo math vector
	struct MousePosition {
		float x = 0.0f;
		float y = 0.0f;
	};

	class Mouse {
	private:
		static constexpr std::size_t ButtonCount = static_cast<std::size_t>(MouseButton::Count);

		std::array<ButtonState, ButtonCount> _buttonStates = {};

		MousePosition _position = {};
		MousePosition _delta = {};
		MousePosition _scroll = {};

	public:
		void beginFrame();

		void endFrame();

		void onMoved(float x, float y, float deltaX, float deltaY);

		void onScrolled(float x, float y);

		void onButtonPressed(MouseButton button);

		void onButtonReleased(MouseButton button);

		void reset();

		[[nodiscard]] bool isButtonDown(MouseButton button) const;

		[[nodiscard]] bool wasButtonPressed(MouseButton button) const;

		[[nodiscard]] bool wasButtonReleased(MouseButton button) const;

	private:
		[[nodiscard]] static constexpr std::size_t index(MouseButton button);

		[[nodiscard]] static constexpr bool isValid(MouseButton button);
	};
}
