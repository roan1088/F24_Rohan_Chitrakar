#pragma once

#include "MeowUtilities.h"

namespace Meow {

class MEOW_API KeyEvent {
public:
	enum class KeyAction{PRESS, RELEASE, REPEAT};

	KeyEvent(int keyCode, KeyAction action = KeyAction::PRESS);

	int GetKeyCode() const;
	KeyAction GetKeyAction() const;

private:
	int mKeyCode{-1};
	KeyAction mAction{KeyAction::PRESS};
};


class MEOW_API WindowEvent {
public:
	enum class WindowAction{CLOSE, MINIMIZE, MAXIMIZE, RESIZE};

	WindowEvent(WindowAction action);

	WindowAction GetWindowAction() const;

private:
	WindowAction mAction{WindowAction::RESIZE};
};

}