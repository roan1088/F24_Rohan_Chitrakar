#pragma once

#include "MeowUtilities.h"

namespace Meow {

class MEOW_API MeowApplication {
public:
	void Run();
	virtual void Initialize();
	virtual void Update();
	virtual void Shutdown();

private:
	bool shouldContinue{true};
};

}