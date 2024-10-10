#pragma once

namespace Meow {

class MeowApplication {
public:
	void Run();
	virtual void Initialize();
	virtual void Update();
	virtual void Shutdown();

private:
	bool shouldContinue{true};
};

}