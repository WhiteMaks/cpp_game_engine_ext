//
// Created by whitemaks on 08.11.2026.
//

#include <stdexcept>

#include <platform/sdl3/Sdl3Window.h>

namespace platform {
	Sdl3Window::Sdl3Window(const engine::WindowDesc &desc) : Window(desc), _window(nullptr) {
	}

	void Sdl3Window::init() {
		SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "x11");

		if (!SDL_Init(SDL_INIT_VIDEO)) {
			throw std::runtime_error(SDL_GetError());
		}

		_window = SDL_CreateWindow(
			_desc.title.c_str(),
			static_cast<int>(_desc.size.width),
			static_cast<int>(_desc.size.height),
			SDL_WINDOW_RESIZABLE
		);

		if (!_window) {
			SDL_QuitSubSystem(SDL_INIT_VIDEO);
			throw std::runtime_error(SDL_GetError());
		}
	}

	void Sdl3Window::input() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					_eventCallback(event::WindowClosedEvent{});
					break;

				case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
					if (event.window.windowID == SDL_GetWindowID(_window)) {
						_eventCallback(event::WindowClosedEvent{});
					}
					break;

				case SDL_EVENT_WINDOW_RESIZED:
					_eventCallback(event::WindowResizedEvent{
						.width = static_cast<std::uint32_t>(event.window.data1),
						.height = static_cast<std::uint32_t>(event.window.data2)
					});
					break;

				case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
					_eventCallback(event::WindowFramebufferResizedEvent{
						.width = static_cast<std::uint32_t>(event.window.data1),
						.height = static_cast<std::uint32_t>(event.window.data2)
					});
					break;

				case SDL_EVENT_WINDOW_FOCUS_GAINED:
					_eventCallback(event::WindowFocusedEvent{});
					break;

				case SDL_EVENT_WINDOW_FOCUS_LOST:
					_eventCallback(event::WindowUnfocusedEvent{});
					break;

				case SDL_EVENT_KEY_DOWN:
					_eventCallback(event::KeyboardButtonPressedEvent{
						.button = toEngineKeyboard(event.key.scancode),
						.repeat = event.key.repeat
					});
					break;

				case SDL_EVENT_KEY_UP:
					_eventCallback(event::KeyboardButtonReleasedEvent{
						.button = toEngineKeyboard(event.key.scancode)
					});
					break;

				case SDL_EVENT_MOUSE_MOTION:
					_eventCallback(event::MouseMovedEvent{
						.x = event.motion.x,
						.y = event.motion.y,
						.deltaX = event.motion.xrel,
						.deltaY = event.motion.yrel,
					});
					break;

				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					_eventCallback(event::MouseButtonPressedEvent{
						.button = toEngineMouse(event.button.button)
					});
					break;

				case SDL_EVENT_MOUSE_BUTTON_UP:
					_eventCallback(event::MouseButtonReleasedEvent{
						.button = toEngineMouse(event.button.button)
					});
					break;

				case SDL_EVENT_MOUSE_WHEEL: {
					const float direction =
							event.wheel.direction == SDL_MOUSEWHEEL_FLIPPED
								? -1.0f
								: 1.0f;

					_eventCallback(event::MouseScrolledEvent{
						.xOffset = event.wheel.x * direction,
						.yOffset = event.wheel.y * direction
					});
					break;
				}

				default:
					break;
			}
		}
	}

	void Sdl3Window::destroy() {
		if (_window) {
			SDL_DestroyWindow(_window);
			_window = nullptr;
		}

		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}

	input::KeyboardButton Sdl3Window::toEngineKeyboard(SDL_Scancode key) {
		switch (key) {
			case SDL_SCANCODE_A: return input::KeyboardButton::A;
			case SDL_SCANCODE_B: return input::KeyboardButton::B;
			case SDL_SCANCODE_C: return input::KeyboardButton::C;
			case SDL_SCANCODE_D: return input::KeyboardButton::D;
			case SDL_SCANCODE_E: return input::KeyboardButton::E;
			case SDL_SCANCODE_F: return input::KeyboardButton::F;
			case SDL_SCANCODE_G: return input::KeyboardButton::G;
			case SDL_SCANCODE_H: return input::KeyboardButton::H;
			case SDL_SCANCODE_I: return input::KeyboardButton::I;
			case SDL_SCANCODE_J: return input::KeyboardButton::J;
			case SDL_SCANCODE_K: return input::KeyboardButton::K;
			case SDL_SCANCODE_L: return input::KeyboardButton::L;
			case SDL_SCANCODE_M: return input::KeyboardButton::M;
			case SDL_SCANCODE_N: return input::KeyboardButton::N;
			case SDL_SCANCODE_O: return input::KeyboardButton::O;
			case SDL_SCANCODE_P: return input::KeyboardButton::P;
			case SDL_SCANCODE_Q: return input::KeyboardButton::Q;
			case SDL_SCANCODE_R: return input::KeyboardButton::R;
			case SDL_SCANCODE_S: return input::KeyboardButton::S;
			case SDL_SCANCODE_T: return input::KeyboardButton::T;
			case SDL_SCANCODE_U: return input::KeyboardButton::U;
			case SDL_SCANCODE_V: return input::KeyboardButton::V;
			case SDL_SCANCODE_W: return input::KeyboardButton::W;
			case SDL_SCANCODE_X: return input::KeyboardButton::X;
			case SDL_SCANCODE_Y: return input::KeyboardButton::Y;
			case SDL_SCANCODE_Z: return input::KeyboardButton::Z;

			case SDL_SCANCODE_1: return input::KeyboardButton::D1;
			case SDL_SCANCODE_2: return input::KeyboardButton::D2;
			case SDL_SCANCODE_3: return input::KeyboardButton::D3;
			case SDL_SCANCODE_4: return input::KeyboardButton::D4;
			case SDL_SCANCODE_5: return input::KeyboardButton::D5;
			case SDL_SCANCODE_6: return input::KeyboardButton::D6;
			case SDL_SCANCODE_7: return input::KeyboardButton::D7;
			case SDL_SCANCODE_8: return input::KeyboardButton::D8;
			case SDL_SCANCODE_9: return input::KeyboardButton::D9;
			case SDL_SCANCODE_0: return input::KeyboardButton::D0;

			case SDL_SCANCODE_F1: return input::KeyboardButton::F1;
			case SDL_SCANCODE_F2: return input::KeyboardButton::F2;
			case SDL_SCANCODE_F3: return input::KeyboardButton::F3;
			case SDL_SCANCODE_F4: return input::KeyboardButton::F4;
			case SDL_SCANCODE_F5: return input::KeyboardButton::F5;
			case SDL_SCANCODE_F6: return input::KeyboardButton::F6;
			case SDL_SCANCODE_F7: return input::KeyboardButton::F7;
			case SDL_SCANCODE_F8: return input::KeyboardButton::F8;
			case SDL_SCANCODE_F9: return input::KeyboardButton::F9;
			case SDL_SCANCODE_F10: return input::KeyboardButton::F10;
			case SDL_SCANCODE_F11: return input::KeyboardButton::F11;
			case SDL_SCANCODE_F12: return input::KeyboardButton::F12;
			case SDL_SCANCODE_F13: return input::KeyboardButton::F13;
			case SDL_SCANCODE_F14: return input::KeyboardButton::F14;
			case SDL_SCANCODE_F15: return input::KeyboardButton::F15;
			case SDL_SCANCODE_F16: return input::KeyboardButton::F16;
			case SDL_SCANCODE_F17: return input::KeyboardButton::F17;
			case SDL_SCANCODE_F18: return input::KeyboardButton::F18;
			case SDL_SCANCODE_F19: return input::KeyboardButton::F19;
			case SDL_SCANCODE_F20: return input::KeyboardButton::F20;
			case SDL_SCANCODE_F21: return input::KeyboardButton::F21;
			case SDL_SCANCODE_F22: return input::KeyboardButton::F22;
			case SDL_SCANCODE_F23: return input::KeyboardButton::F23;
			case SDL_SCANCODE_F24: return input::KeyboardButton::F24;

			case SDL_SCANCODE_GRAVE: return input::KeyboardButton::Grave;
			case SDL_SCANCODE_MINUS: return input::KeyboardButton::Minus;
			case SDL_SCANCODE_EQUALS: return input::KeyboardButton::Equal;
			case SDL_SCANCODE_LEFTBRACKET: return input::KeyboardButton::LeftBracket;
			case SDL_SCANCODE_RIGHTBRACKET: return input::KeyboardButton::RightBracket;
			case SDL_SCANCODE_BACKSLASH: return input::KeyboardButton::Backslash;
			case SDL_SCANCODE_SEMICOLON: return input::KeyboardButton::Semicolon;
			case SDL_SCANCODE_APOSTROPHE: return input::KeyboardButton::Apostrophe;
			case SDL_SCANCODE_COMMA: return input::KeyboardButton::Comma;
			case SDL_SCANCODE_PERIOD: return input::KeyboardButton::Period;
			case SDL_SCANCODE_SLASH: return input::KeyboardButton::Slash;

			case SDL_SCANCODE_LSHIFT: return input::KeyboardButton::LeftShift;
			case SDL_SCANCODE_RSHIFT: return input::KeyboardButton::RightShift;
			case SDL_SCANCODE_LCTRL: return input::KeyboardButton::LeftControl;
			case SDL_SCANCODE_RCTRL: return input::KeyboardButton::RightControl;
			case SDL_SCANCODE_LALT: return input::KeyboardButton::LeftAlt;
			case SDL_SCANCODE_RALT: return input::KeyboardButton::RightAlt;
			case SDL_SCANCODE_LGUI: return input::KeyboardButton::LeftSuper;
			case SDL_SCANCODE_RGUI: return input::KeyboardButton::RightSuper;

			case SDL_SCANCODE_SPACE: return input::KeyboardButton::Space;
			case SDL_SCANCODE_ESCAPE: return input::KeyboardButton::Escape;
			case SDL_SCANCODE_RETURN: return input::KeyboardButton::Enter;
			case SDL_SCANCODE_TAB: return input::KeyboardButton::Tab;
			case SDL_SCANCODE_BACKSPACE: return input::KeyboardButton::Backspace;
			case SDL_SCANCODE_CAPSLOCK: return input::KeyboardButton::CapsLock;

			case SDL_SCANCODE_INSERT: return input::KeyboardButton::Insert;
			case SDL_SCANCODE_DELETE: return input::KeyboardButton::Delete;
			case SDL_SCANCODE_HOME: return input::KeyboardButton::Home;
			case SDL_SCANCODE_END: return input::KeyboardButton::End;
			case SDL_SCANCODE_PAGEUP: return input::KeyboardButton::PageUp;
			case SDL_SCANCODE_PAGEDOWN: return input::KeyboardButton::PageDown;

			case SDL_SCANCODE_UP: return input::KeyboardButton::Up;
			case SDL_SCANCODE_DOWN: return input::KeyboardButton::Down;
			case SDL_SCANCODE_LEFT: return input::KeyboardButton::Left;
			case SDL_SCANCODE_RIGHT: return input::KeyboardButton::Right;

			case SDL_SCANCODE_NUMLOCKCLEAR: return input::KeyboardButton::NumLock;
			case SDL_SCANCODE_KP_0: return input::KeyboardButton::Keypad0;
			case SDL_SCANCODE_KP_1: return input::KeyboardButton::Keypad1;
			case SDL_SCANCODE_KP_2: return input::KeyboardButton::Keypad2;
			case SDL_SCANCODE_KP_3: return input::KeyboardButton::Keypad3;
			case SDL_SCANCODE_KP_4: return input::KeyboardButton::Keypad4;
			case SDL_SCANCODE_KP_5: return input::KeyboardButton::Keypad5;
			case SDL_SCANCODE_KP_6: return input::KeyboardButton::Keypad6;
			case SDL_SCANCODE_KP_7: return input::KeyboardButton::Keypad7;
			case SDL_SCANCODE_KP_8: return input::KeyboardButton::Keypad8;
			case SDL_SCANCODE_KP_9: return input::KeyboardButton::Keypad9;
			case SDL_SCANCODE_KP_DECIMAL: return input::KeyboardButton::KeypadDecimal;
			case SDL_SCANCODE_KP_DIVIDE: return input::KeyboardButton::KeypadDivide;
			case SDL_SCANCODE_KP_MULTIPLY: return input::KeyboardButton::KeypadMultiply;
			case SDL_SCANCODE_KP_MINUS: return input::KeyboardButton::KeypadSubtract;
			case SDL_SCANCODE_KP_PLUS: return input::KeyboardButton::KeypadAdd;
			case SDL_SCANCODE_KP_ENTER: return input::KeyboardButton::KeypadEnter;
			case SDL_SCANCODE_KP_EQUALS: return input::KeyboardButton::KeypadEqual;

			case SDL_SCANCODE_PRINTSCREEN: return input::KeyboardButton::PrintScreen;
			case SDL_SCANCODE_SCROLLLOCK: return input::KeyboardButton::ScrollLock;
			case SDL_SCANCODE_PAUSE: return input::KeyboardButton::Pause;
			case SDL_SCANCODE_MENU: return input::KeyboardButton::Menu;

			default:
				return input::KeyboardButton::Unknown;
		}
	}

	input::MouseButton Sdl3Window::toEngineMouse(std::uint8_t button) {
		switch (button) {
			case SDL_BUTTON_LEFT: return input::MouseButton::Left;
			case SDL_BUTTON_RIGHT: return input::MouseButton::Right;
			case SDL_BUTTON_MIDDLE: return input::MouseButton::Middle;
			case SDL_BUTTON_X1: return input::MouseButton::Button4;
			case SDL_BUTTON_X2: return input::MouseButton::Button5;
			case 6: return input::MouseButton::Button6;
			case 7: return input::MouseButton::Button7;
			case 8: return input::MouseButton::Button8;

			default:
				return input::MouseButton::Unknown;
		}
	}
}
