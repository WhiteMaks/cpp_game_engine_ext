//
// Created by whitemaks on 14.11.2026.
//

#include <engine/input/ButtonState.h>

namespace input {
	void ButtonState::beginFrame() {
		_pressed = false;
		_released = false;
	}

	void ButtonState::endFrame() {
		_pressed = false;
		_released = false;
	}

	void ButtonState::press() {
		if (!_down) {
			_down = true;
			_pressed = true;
		}
	}

	void ButtonState::release() {
		if (_down) {
			_down = false;
			_released = true;
		}
	}

	void ButtonState::reset() {
		_down = false;
		_pressed = false;
		_released = false;
	}

	bool ButtonState::isDown() const {
		return _down;
	}

	bool ButtonState::wasPressed() const {
		return _pressed;
	}

	bool ButtonState::wasReleased() const {
		return _released;
	}
}
