//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <cstdint>

namespace event {
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
		Menu
	};

	struct KeyboardButtonPressedEvent
	{
		KeyboardButton button = KeyboardButton::Unknown;
		bool repeat = false;
	};

	struct KeyboardButtonReleasedEvent
	{
		KeyboardButton button = KeyboardButton::Unknown;
	};
}
