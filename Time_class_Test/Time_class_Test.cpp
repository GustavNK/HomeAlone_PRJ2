#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/Time_class.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeclassTest
{
	TEST_CLASS(TimeclassTest)
	{
	public:
		
		//In testing all constructors, all getters 
		//and setters have been tested as well.
		//Test default constructor
		TEST_METHOD(Time_Default_Constr)
		{
			int t1 = 0;
			Time_class test1;
			Assert::AreEqual(t1, test1.getHour());
			Assert::AreEqual(t1, test1.getMin());
			Assert::AreEqual(t1, test1.getSec());
		}

		//Test constructor w values 
		TEST_METHOD(Time_Constr_Val)
		{
			int t1 = 10;
			Time_class test1(t1,t1,t1);
			Assert::AreEqual(t1, test1.getHour());
			Assert::AreEqual(t1, test1.getMin());
			Assert::AreEqual(t1, test1.getSec());
		}

		//Test constructor - hr wrong
		TEST_METHOD(Time_Constr_Hr)
		{
			int t1 = 25;
			int default_value = 0;
			Time_class test1(t1,t1,t1);
			Assert::AreEqual(default_value, test1.getHour());

		}

		//Test constructor - min wrong
		TEST_METHOD(Time_Constr_Min)
		{
			int t1 = 65;
			int default_value = 0;
			Time_class test1(t1, t1, t1);
			Assert::AreEqual(default_value, test1.getMin());
		}

		//Test GetTime object
		TEST_METHOD(Time_GetTime)
		{
			int t1 = 15;
			int t2, t3;
			Time_class test1(t1, t1, t1);
			test1.getTime_class(t2, t3);
			Assert::AreEqual(t1, t2);
			Assert::AreEqual(t1, t3);
		}

	};
}
