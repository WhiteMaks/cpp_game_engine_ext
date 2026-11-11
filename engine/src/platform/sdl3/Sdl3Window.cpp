//
// Created by whitemaks on 08.11.2026.
//

#include <stdexcept>

#include <platform/sdl3/Sdl3Window.h>

namespace platform {
	Sdl3Window::Sdl3Window(const engine::WindowDesc &desc) : Window(desc), _window(nullptr) {
	}

	void Sdl3Window::init() {
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
						.y = event.motion.y
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

	event::KeyboardButton Sdl3Window::toEngineKeyboard(SDL_Scancode key) {
		switch (key) {
			case SDL_SCANCODE_A: return event::KeyboardButton::A;
			case SDL_SCANCODE_B: return event::KeyboardButton::B;
			case SDL_SCANCODE_C: return event::KeyboardButton::C;
			case SDL_SCANCODE_D: return event::KeyboardButton::D;
			case SDL_SCANCODE_E: return event::KeyboardButton::E;
			case SDL_SCANCODE_F: return event::KeyboardButton::F;
			case SDL_SCANCODE_G: return event::KeyboardButton::G;
			case SDL_SCANCODE_H: return event::KeyboardButton::H;
			case SDL_SCANCODE_I: return event::KeyboardButton::I;
			case SDL_SCANCODE_J: return event::KeyboardButton::J;
			case SDL_SCANCODE_K: return event::KeyboardButton::K;
			case SDL_SCANCODE_L: return event::KeyboardButton::L;
			case SDL_SCANCODE_M: return event::KeyboardButton::M;
			case SDL_SCANCODE_N: return event::KeyboardButton::N;
			case SDL_SCANCODE_O: return event::KeyboardButton::O;
			case SDL_SCANCODE_P: return event::KeyboardButton::P;
			case SDL_SCANCODE_Q: return event::KeyboardButton::Q;
			case SDL_SCANCODE_R: return event::KeyboardButton::R;
			case SDL_SCANCODE_S: return event::KeyboardButton::S;
			case SDL_SCANCODE_T: return event::KeyboardButton::T;
			case SDL_SCANCODE_U: return event::KeyboardButton::U;
			case SDL_SCANCODE_V: return event::KeyboardButton::V;
			case SDL_SCANCODE_W: return event::KeyboardButton::W;
			case SDL_SCANCODE_X: return event::KeyboardButton::X;
			case SDL_SCANCODE_Y: return event::KeyboardButton::Y;
			case SDL_SCANCODE_Z: return event::KeyboardButton::Z;

			case SDL_SCANCODE_1: return event::KeyboardButton::D1;
			case SDL_SCANCODE_2: return event::KeyboardButton::D2;
			case SDL_SCANCODE_3: return event::KeyboardButton::D3;
			case SDL_SCANCODE_4: return event::KeyboardButton::D4;
			case SDL_SCANCODE_5: return event::KeyboardButton::D5;
			case SDL_SCANCODE_6: return event::KeyboardButton::D6;
			case SDL_SCANCODE_7: return event::KeyboardButton::D7;
			case SDL_SCANCODE_8: return event::KeyboardButton::D8;
			case SDL_SCANCODE_9: return event::KeyboardButton::D9;
			case SDL_SCANCODE_0: return event::KeyboardButton::D0;

			case SDL_SCANCODE_F1: return event::KeyboardButton::F1;
			case SDL_SCANCODE_F2: return event::KeyboardButton::F2;
			case SDL_SCANCODE_F3: return event::KeyboardButton::F3;
			case SDL_SCANCODE_F4: return event::KeyboardButton::F4;
			case SDL_SCANCODE_F5: return event::KeyboardButton::F5;
			case SDL_SCANCODE_F6: return event::KeyboardButton::F6;
			case SDL_SCANCODE_F7: return event::KeyboardButton::F7;
			case SDL_SCANCODE_F8: return event::KeyboardButton::F8;
			case SDL_SCANCODE_F9: return event::KeyboardButton::F9;
			case SDL_SCANCODE_F10: return event::KeyboardButton::F10;
			case SDL_SCANCODE_F11: return event::KeyboardButton::F11;
			case SDL_SCANCODE_F12: return event::KeyboardButton::F12;
			case SDL_SCANCODE_F13: return event::KeyboardButton::F13;
			case SDL_SCANCODE_F14: return event::KeyboardButton::F14;
			case SDL_SCANCODE_F15: return event::KeyboardButton::F15;
			case SDL_SCANCODE_F16: return event::KeyboardButton::F16;
			case SDL_SCANCODE_F17: return event::KeyboardButton::F17;
			case SDL_SCANCODE_F18: return event::KeyboardButton::F18;
			case SDL_SCANCODE_F19: return event::KeyboardButton::F19;
			case SDL_SCANCODE_F20: return event::KeyboardButton::F20;
			case SDL_SCANCODE_F21: return event::KeyboardButton::F21;
			case SDL_SCANCODE_F22: return event::KeyboardButton::F22;
			case SDL_SCANCODE_F23: return event::KeyboardButton::F23;
			case SDL_SCANCODE_F24: return event::KeyboardButton::F24;

			case SDL_SCANCODE_GRAVE: return event::KeyboardButton::Grave;
			case SDL_SCANCODE_MINUS: return event::KeyboardButton::Minus;
			case SDL_SCANCODE_EQUALS: return event::KeyboardButton::Equal;
			case SDL_SCANCODE_LEFTBRACKET: return event::KeyboardButton::LeftBracket;
			case SDL_SCANCODE_RIGHTBRACKET: return event::KeyboardButton::RightBracket;
			case SDL_SCANCODE_BACKSLASH: return event::KeyboardButton::Backslash;
			case SDL_SCANCODE_SEMICOLON: return event::KeyboardButton::Semicolon;
			case SDL_SCANCODE_APOSTROPHE: return event::KeyboardButton::Apostrophe;
			case SDL_SCANCODE_COMMA: return event::KeyboardButton::Comma;
			case SDL_SCANCODE_PERIOD: return event::KeyboardButton::Period;
			case SDL_SCANCODE_SLASH: return event::KeyboardButton::Slash;

			case SDL_SCANCODE_LSHIFT: return event::KeyboardButton::LeftShift;
			case SDL_SCANCODE_RSHIFT: return event::KeyboardButton::RightShift;
			case SDL_SCANCODE_LCTRL: return event::KeyboardButton::LeftControl;
			case SDL_SCANCODE_RCTRL: return event::KeyboardButton::RightControl;
			case SDL_SCANCODE_LALT: return event::KeyboardButton::LeftAlt;
			case SDL_SCANCODE_RALT: return event::KeyboardButton::RightAlt;
			case SDL_SCANCODE_LGUI: return event::KeyboardButton::LeftSuper;
			case SDL_SCANCODE_RGUI: return event::KeyboardButton::RightSuper;

			case SDL_SCANCODE_SPACE: return event::KeyboardButton::Space;
			case SDL_SCANCODE_ESCAPE: return event::KeyboardButton::Escape;
			case SDL_SCANCODE_RETURN: return event::KeyboardButton::Enter;
			case SDL_SCANCODE_TAB: return event::KeyboardButton::Tab;
			case SDL_SCANCODE_BACKSPACE: return event::KeyboardButton::Backspace;
			case SDL_SCANCODE_CAPSLOCK: return event::KeyboardButton::CapsLock;

			case SDL_SCANCODE_INSERT: return event::KeyboardButton::Insert;
			case SDL_SCANCODE_DELETE: return event::KeyboardButton::Delete;
			case SDL_SCANCODE_HOME: return event::KeyboardButton::Home;
			case SDL_SCANCODE_END: return event::KeyboardButton::End;
			case SDL_SCANCODE_PAGEUP: return event::KeyboardButton::PageUp;
			case SDL_SCANCODE_PAGEDOWN: return event::KeyboardButton::PageDown;

			case SDL_SCANCODE_UP: return event::KeyboardButton::Up;
			case SDL_SCANCODE_DOWN: return event::KeyboardButton::Down;
			case SDL_SCANCODE_LEFT: return event::KeyboardButton::Left;
			case SDL_SCANCODE_RIGHT: return event::KeyboardButton::Right;

			case SDL_SCANCODE_NUMLOCKCLEAR: return event::KeyboardButton::NumLock;
			case SDL_SCANCODE_KP_0: return event::KeyboardButton::Keypad0;
			case SDL_SCANCODE_KP_1: return event::KeyboardButton::Keypad1;
			case SDL_SCANCODE_KP_2: return event::KeyboardButton::Keypad2;
			case SDL_SCANCODE_KP_3: return event::KeyboardButton::Keypad3;
			case SDL_SCANCODE_KP_4: return event::KeyboardButton::Keypad4;
			case SDL_SCANCODE_KP_5: return event::KeyboardButton::Keypad5;
			case SDL_SCANCODE_KP_6: return event::KeyboardButton::Keypad6;
			case SDL_SCANCODE_KP_7: return event::KeyboardButton::Keypad7;
			case SDL_SCANCODE_KP_8: return event::KeyboardButton::Keypad8;
			case SDL_SCANCODE_KP_9: return event::KeyboardButton::Keypad9;
			case SDL_SCANCODE_KP_DECIMAL: return event::KeyboardButton::KeypadDecimal;
			case SDL_SCANCODE_KP_DIVIDE: return event::KeyboardButton::KeypadDivide;
			case SDL_SCANCODE_KP_MULTIPLY: return event::KeyboardButton::KeypadMultiply;
			case SDL_SCANCODE_KP_MINUS: return event::KeyboardButton::KeypadSubtract;
			case SDL_SCANCODE_KP_PLUS: return event::KeyboardButton::KeypadAdd;
			case SDL_SCANCODE_KP_ENTER: return event::KeyboardButton::KeypadEnter;
			case SDL_SCANCODE_KP_EQUALS: return event::KeyboardButton::KeypadEqual;

			case SDL_SCANCODE_PRINTSCREEN: return event::KeyboardButton::PrintScreen;
			case SDL_SCANCODE_SCROLLLOCK: return event::KeyboardButton::ScrollLock;
			case SDL_SCANCODE_PAUSE: return event::KeyboardButton::Pause;
			case SDL_SCANCODE_MENU: return event::KeyboardButton::Menu;

			default:
				return event::KeyboardButton::Unknown;
		}
	}

	event::MouseButton Sdl3Window::toEngineMouse(std::uint8_t button) {
		switch (button) {
			case SDL_BUTTON_LEFT: return event::MouseButton::Left;
			case SDL_BUTTON_RIGHT: return event::MouseButton::Right;
			case SDL_BUTTON_MIDDLE: return event::MouseButton::Middle;
			case SDL_BUTTON_X1: return event::MouseButton::Button4;
			case SDL_BUTTON_X2: return event::MouseButton::Button5;
			case 6: return event::MouseButton::Button6;
			case 7: return event::MouseButton::Button7;
			case 8: return event::MouseButton::Button8;

			default:
				return event::MouseButton::Unknown;
		}
	}
}
