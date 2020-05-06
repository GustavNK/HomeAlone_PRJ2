#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/TimeInterval.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeIntervalTest
{
	TEST_CLASS(TimeIntervalTest)
	{
	public:
		
		//Test default constructor
		TEST_METHOD(Test_Default_Constr)
		{
			TimeInterval ti1;
			int default_value = 0;
			Assert::AreEqual(default_value, ti1.getStartTime().getHour());
			Assert::AreEqual(default_value, ti1.getStartTime().getMin());
			Assert::AreEqual(default_value, ti1.getEndTime().getHour());
			Assert::AreEqual(default_value, ti1.getEndTime().getMin());
		}

		//Test constructor w values
		TEST_METHOD(Test_Constr)
		{
			int t1 = 14;
			int t2 = 12;
			TimeInterval ti1(t1,t1,t2,t2);
			Assert::AreEqual(t1, ti1.getStartTime().getHour());
			Assert::AreEqual(t1, ti1.getStartTime().getMin());
			Assert::AreEqual(t2, ti1.getEndTime().getHour());
			Assert::AreEqual(t2, ti1.getEndTime().getMin());
		}

		//Test af setter
		TEST_METHOD(Test_SetStart_SetEnd)
		{
			int t1 = 14;
			int t2 = 12;
			TimeInterval ti1;
			ti1.setStartTime(t1, t2);
			ti1.setEndTime(t2, t1);
			Assert::AreEqual(t1, ti1.getStartTime().getHour());
			Assert::AreEqual(t2, ti1.getStartTime().getMin());
			Assert::AreEqual(t2, ti1.getEndTime().getHour());
			Assert::AreEqual(t1, ti1.getEndTime().getMin());
		}



	};
}
