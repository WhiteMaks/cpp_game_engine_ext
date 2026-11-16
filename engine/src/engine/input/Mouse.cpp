//
// Created by whitemaks on 14.11.2026.
//

#include <engine/input/Mouse.h>

namespace input {
	void Mouse::beginFrame() {
		for (ButtonState state : _buttonStates) {
			state.beginFrame();
		}

		_delta = {};
		_scroll = {};
	}

	void Mouse::endFrame() {
		for (ButtonState state : _buttonStates) {
			state.endFrame();
		}

		_delta = {};
		_scroll = {};
	}

	void Mouse::onMoved(const float x, const float y, const float deltaX, const float deltaY) {
		_position = {
			.x = x,
			.y = y
		};

		_delta = {
			.x = deltaX,
			.y = deltaY
		};
	}

	void Mouse::onScrolled(const float x, const float y) {
		_scroll = {
			.x = x,
			.y = y
		};
	}

	void Mouse::onButtonPressed(const MouseButton button) {
		if (isValid(button)) {
			_buttonStates[index(button)].press();
		}
	}

	void Mouse::onButtonReleased(const MouseButton button) {
		if (isValid(button)) {
			_buttonStates[index(button)].release();
		}
	}

	void Mouse::reset() {
		for (ButtonState state : _buttonStates) {
			state.reset();
		}

		_delta = {};
		_scroll = {};
	}

	bool Mouse::isButtonDown(const MouseButton button) const {
		return isValid(button) && _buttonStates[index(button)].isDown();
	}

	bool Mouse::wasButtonPressed(const MouseButton button) const {
		return isValid(button) && _buttonStates[index(button)].wasPressed();
	}

	bool Mouse::wasButtonReleased(const MouseButton button) const {
		return isValid(button) && _buttonStates[index(button)].wasReleased();
	}

	constexpr std::size_t Mouse::index(MouseButton button) {
		return static_cast<std::size_t>(button);
	}

	constexpr bool Mouse::isValid(const MouseButton button) {
		return button != MouseButton::Unknown && index(button) < ButtonCount;
	}
}
