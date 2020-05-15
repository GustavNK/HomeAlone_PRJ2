#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAlone/DE2_Driver.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DE2test
{
	TEST_CLASS(DE2test)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			DE2_driver de2 = DE2_driver(3, 9600);
			Assert::AreEqual(2, 2);
		}
		TEST_METHOD(Receive)
		{
			DE2_driver de2 = DE2_driver(3, 9600);
			bool temp = de2.readDE2();
			Assert::AreEqual(true, temp);
		}
	};
}
