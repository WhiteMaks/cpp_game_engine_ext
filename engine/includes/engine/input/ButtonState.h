//
// Created by whitemaks on 14.11.2026.
//

#pragma once

namespace input {
	class ButtonState {
	private:
		bool _down = false;
		bool _pressed = false;
		bool _released = false;

	public:
		void beginFrame();

		void endFrame();

		void press();

		void release();

		void reset();

		[[nodiscard]] bool isDown() const;

		[[nodiscard]] bool wasPressed() const;

		[[nodiscard]] bool wasReleased() const;
	};
}
