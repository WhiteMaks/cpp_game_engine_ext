//
// Created by whitemaks on 14.11.2026.
//

#include <engine/input/InputSystem.h>

namespace input {
	void InputSystem::beginFrame() {
		_keyboard.beginFrame();
		_mouse.beginFrame();
	}

	void InputSystem::endFrame() {
		_keyboard.endFrame();
		_mouse.endFrame();
	}

	void InputSystem::onEvent(const event::KeyboardButtonPressedEvent &event) {
		_keyboard.onButtonPressed(event.button);
	}

	void InputSystem::onEvent(const event::KeyboardButtonReleasedEvent &event) {
		_keyboard.onButtonReleased(event.button);
	}

	void InputSystem::onEvent(const event::MouseButtonPressedEvent &event) {
		_mouse.onButtonPressed(event.button);
	}

	void InputSystem::onEvent(const event::MouseButtonReleasedEvent &event) {
		_mouse.onButtonReleased(event.button);
	}

	void InputSystem::onEvent(const event::MouseScrolledEvent &event) {
		_mouse.onScrolled(event.xOffset, event.yOffset);
	}

	void InputSystem::onEvent(const event::MouseMovedEvent &event) {
		_mouse.onMoved(event.x, event.y, event.deltaX, event.deltaY);
	}

	bool InputSystem::isActionDown(const std::string &name) {
		return _inputActionMap.isActionDown(name, _mouse, _keyboard);
	}

	bool InputSystem::wasActionPressed(const std::string &name) {
		return _inputActionMap.wasActionPressed(name, _mouse, _keyboard);
	}

	bool InputSystem::wasActionReleased(const std::string &name) {
		return _inputActionMap.wasActionReleased(name, _mouse, _keyboard);
	}

	Keyboard & InputSystem::getKeyboard() noexcept {
		return _keyboard;
	}

	Mouse & InputSystem::getMouse() noexcept {
		return _mouse;
	}

	InputActionMap & InputSystem::getInputActionMap() noexcept {
		return _inputActionMap;
	}
}
