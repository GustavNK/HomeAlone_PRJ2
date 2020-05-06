#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/Activity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ActivityClassTester
{
	TEST_CLASS(ActivityClassTester)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string reason = "Log in.";
			Activity a1("Log in.");
			Assert::AreEqual(reason, a1.getReason());
		}
	};
}
