#ifndef ARDUINOABSTRACT_HPP
#define ARDUINOABSTRACT_HPP

class Button {
  private:
    int buttonPinNumber;
		int buttonPinMode;
  public:
    Button(int pinNumber): buttonPinNumber(pinNumber) {}
	void init(int mode) {
		this->buttonPinMode = mode;
		pinMode(this->buttonPinNumber, this->buttonPinMode);
	}
	int getState(bool enable = true) {
		if(!enable) {return -1;}
		switch(this->buttonPinMode) {
			case INPUT_PULLUP:
				return !digitalRead(this->buttonPinNumber);
				break;
			case INPUT:
				return digitalRead(this->buttonPinNumber);
				break;
		}
	}
};


class Joystick {
	private:
		int vertical;
		int horizontal;
		int select;
		int maxValue;
		int midValue;
		int minValue;
	public:
		Joystick(int verticalPin, int horizontalPin, int selectPin, int max = 1023, int mid = 512, int min = 0): vertical(verticalPin), horizontal(horizontalPin), select(selectPin), maxValue(max), midValue(min), minValue(min) {}
		void init(int selectMode = INPUT_PULLUP) {
			pinMode(this->vertical, INPUT);
			pinMode(this->horizontal, INPUT);
			pinMode(this->select, selectMode);
		}
		int getHorizontalRead() {
			return analogRead(this->horizontal);
		}
		int getVerticalRead() {
			return analogRead(this->vertical);
		}
		int getSelectState() {
			return !digitalRead(this->select);
		}
		int getPos() {
			// None: -1, Top: 0, Right: 1, Down: 2, Left: 3, TopRight: 4, BottomRight: 5, BottomLeft: 6, TopLeft: 7
			int verticalAxis = this->getVerticalRead();
			int horizontalAxis = this->getHorizontalRead();

			if (verticalAxis == this->maxValue) {
					if (horizontalAxis == this->midValue) return 0; // Top
					if (horizontalAxis == this->maxValue) return 7; // TopLeft
					if (horizontalAxis == this->minValue) return 4; // TopRight
			} else if (verticalAxis == this->minValue) {
					if (horizontalAxis == this->midValue) return 2; // Down
					if (horizontalAxis == this->maxValue) return 6; // BottomLeft
					if (horizontalAxis == this->minValue) return 5; // BottomRight
			} else if (verticalAxis == this->midValue) {
					if (horizontalAxis == this->minValue) return 1; // Right
					if (horizontalAxis == this->maxValue) return 3; // Left
			}

			return -1; // Default case
	}	
};

class Potentiometer {
	private:
		int pinNumber;
	public:
		Potentiometer(int pin): pinNumber(pin) {}
		void init() {
			pinMode(this->pinNumber, INPUT);
		}
		int getValue(bool enable = true) {
			if (!enable) {return -1};
			return analogRead(this->pinNumber);
		}
};

#endif // ARDUINOABSTRACT_HPP