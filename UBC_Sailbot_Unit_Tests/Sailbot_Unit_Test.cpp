#include "stdafx.h"
#include "CppUnitTest.h"
#include "../UBC_Sailbot/StandardCalc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UBC_Sailbot_Unit_Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			StandardCalc standard_calc;

			// already bound within the ranges of -180 and 180
			Assert::AreEqual(-180.0f, standard_calc.BoundTo180(-180.0f), L"message", LINE_INFO());
			Assert::AreEqual(179.99f, standard_calc.BoundTo180(179.99f), L"message", LINE_INFO());

			// just outside of the bound of 179.999...
			Assert::AreEqual(-180.0f, standard_calc.BoundTo180(180.0f), L"message", LINE_INFO());
			Assert::AreEqual(-179.5f, standard_calc.BoundTo180(180.5f), L"message", LINE_INFO());

			// outside the bounds
			Assert::AreEqual(0.0f, standard_calc.BoundTo180(-360.00f), L"message", LINE_INFO());
			Assert::AreEqual(0.0f, standard_calc.BoundTo180(-720.00f), L"message", LINE_INFO());
			Assert::AreEqual(0.0f, standard_calc.BoundTo180(360.00f), L"message", LINE_INFO());
			Assert::AreEqual(0.0f, standard_calc.BoundTo180(720.00f), L"message", LINE_INFO());
			Assert::AreEqual(-90.0f, standard_calc.BoundTo180(-450.0f), L"message", LINE_INFO());
			Assert::AreEqual(-90.0f, standard_calc.BoundTo180(270.0f), L"message", LINE_INFO());
			Assert::AreEqual(100.5500000f, standard_calc.BoundTo180(460.5500000f), 0.0001f);
			Assert::AreEqual(100.5422f, standard_calc.BoundTo180(460.5422f), 0.0001f);
		}

		TEST_METHOD(TestMethod2) {
			StandardCalc standard_calc;

			// middle angle is one of the outer angles
			Assert::AreEqual(false, standard_calc.IsAngleBetween(-180.0f, -10.0f, -10.0f), L"message", LINE_INFO());
			Assert::AreEqual(false, standard_calc.IsAngleBetween(-170.0f, -170.0f, 15.0f), L"message", LINE_INFO());
			
			// test within range
			Assert::AreEqual(true, standard_calc.IsAngleBetween(-90.0f, -180.0f, 110.0f), L"message", LINE_INFO());
			Assert::AreEqual(true, standard_calc.IsAngleBetween(-40.0f, 720.0f, 90.0f), L"message", LINE_INFO());
			
			// test angle that is not within the range of the two angles
			Assert::AreEqual(false, standard_calc.IsAngleBetween(-90.0f, -180.0f, 80.0f), L"message", LINE_INFO());
			Assert::AreEqual(false, standard_calc.IsAngleBetween(15.0f, 475.0f, 90.0f), L"message", LINE_INFO());
		}

	};
}