#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/Log.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogClassTester
{
	TEST_CLASS(LogClassTester)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Log logList;
			logList.archiveNewActivity("1");
		}
	};
}
