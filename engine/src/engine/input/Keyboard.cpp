//
// Created by whitemaks on 14.11.2026.
//

#include <engine/input/Keyboard.h>

namespace input {
	void Keyboard::beginFrame() const {
		for (ButtonState state : _buttonStates) {
			state.beginFrame();
		}
	}

	void Keyboard::endFrame() const {
		for (ButtonState state : _buttonStates) {
			state.endFrame();
		}
	}

	void Keyboard::onButtonPressed(const KeyboardButton button) {
		if (isValid(button)) {
			_buttonStates[index(button)].press();
		}
	}

	void Keyboard::onButtonReleased(const KeyboardButton button) {
		if (isValid(button)) {
			_buttonStates[index(button)].release();
		}
	}

	void Keyboard::reset() const {
		for (ButtonState state : _buttonStates) {
			state.reset();
		}
	}

	bool Keyboard::isButtonDown(const KeyboardButton button) const {
		return isValid(button) && _buttonStates[index(button)].isDown();
	}

	bool Keyboard::wasButtonPressed(const KeyboardButton button) const {
		return isValid(button) && _buttonStates[index(button)].wasPressed();
	}

	bool Keyboard::wasButtonReleased(const KeyboardButton button) const {
		return isValid(button) && _buttonStates[index(button)].wasReleased();
	}

	constexpr std::size_t Keyboard::index(KeyboardButton button) {
		return static_cast<std::size_t>(button);
	}

	constexpr bool Keyboard::isValid(const KeyboardButton button) {
		return button != KeyboardButton::Unknown && index(button) < ButtonCount;
	}
}
