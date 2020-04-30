#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/Time_class.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeclassTest
{
	TEST_CLASS(TimeclassTest)
	{
	public:
		
		//Test constructor/getter hr + min
		TEST_METHOD(TimeConstr)
		{
			int t1 = 10;
			int t2 = 20;
			Time_class test1(t1, t2);
			Assert::AreEqual(t1, test1.getHour());
			//t1= t1 * 2;
			//Assert::AreEqual(t1, t2);
		}
	};
}
