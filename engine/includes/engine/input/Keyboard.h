//
// Created by whitemaks on 14.11.2026.
//

#pragma once

#include <array>
#include <cstdint>

#include <engine/input/ButtonState.h>

namespace input {
	enum class KeyboardButton : std::uint16_t
	{
		Unknown = 0,

		A, B, C, D, E, F, G,
		H, I, J, K, L, M, N,
		O, P, Q, R, S, T, U,
		V, W, X, Y, Z,

		D1, D2, D3, D4, D5,
		D6, D7, D8, D9, D0,

		F1, F2, F3, F4, F5, F6,
		F7, F8, F9, F10, F11, F12,
		F13, F14, F15, F16, F17, F18,
		F19, F20, F21, F22, F23, F24,

		Grave,
		Minus,
		Equal,
		LeftBracket,
		RightBracket,
		Backslash,
		Semicolon,
		Apostrophe,
		Comma,
		Period,
		Slash,

		LeftShift,
		RightShift,
		LeftControl,
		RightControl,
		LeftAlt,
		RightAlt,
		LeftSuper,
		RightSuper,

		Space,
		Escape,
		Enter,
		Tab,
		Backspace,
		CapsLock,

		Insert,
		Delete,
		Home,
		End,
		PageUp,
		PageDown,

		Up,
		Down,
		Left,
		Right,

		NumLock,
		Keypad0,
		Keypad1,
		Keypad2,
		Keypad3,
		Keypad4,
		Keypad5,
		Keypad6,
		Keypad7,
		Keypad8,
		Keypad9,
		KeypadDecimal,
		KeypadDivide,
		KeypadMultiply,
		KeypadSubtract,
		KeypadAdd,
		KeypadEnter,
		KeypadEqual,

		PrintScreen,
		ScrollLock,
		Pause,
		Menu,

		Count
	};

	class Keyboard {
	private:
		static constexpr std::size_t ButtonCount = static_cast<std::size_t>(KeyboardButton::Count);

		std::array<ButtonState, ButtonCount> _buttonStates = {};

	public:
		void beginFrame();

		void endFrame();

		void onButtonPressed(KeyboardButton button);

		void onButtonReleased(KeyboardButton button);

		void reset();

		[[nodiscard]] bool isButtonDown(KeyboardButton button) const;

		[[nodiscard]] bool wasButtonPressed(KeyboardButton button) const;

		[[nodiscard]] bool wasButtonReleased(KeyboardButton button) const;

	private:
		[[nodiscard]] static constexpr std::size_t index(KeyboardButton button);

		[[nodiscard]] static constexpr bool isValid(KeyboardButton button);
	};
}
