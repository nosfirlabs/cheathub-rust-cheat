#pragma once

#include "etc.h"

class TestHookStuff {
public:
	void testload();
};

inline TestHookStuff* g_TestHook = new TestHookStuff;