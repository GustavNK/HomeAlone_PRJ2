#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/Activity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ActivityClassTester
{
	TEST_CLASS(ActivityClassTester)
	{
	public:
		
		TEST_METHOD(getReason)
		{
			Activity a1("Log in.");
			
			string reason = "Log in.";
			Assert::AreEqual(reason, a1.getReason());
		}

		TEST_METHOD(getDateTime)
		{
			Activity a1("Log in.");

			time_t dateTime = time(0);
			Assert::AreEqual(dateTime, a1.getDateTime()); //Virker ikke?
		}
	};
}
