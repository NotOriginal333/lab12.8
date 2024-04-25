#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.8/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TrainStation station;
			station.addTrain(101, "08:00");

			Train* head = station.getFirstTrain();

			Assert::AreEqual(101, head->number);
		}
	};
}
