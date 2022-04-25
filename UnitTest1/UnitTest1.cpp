#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.2.2/Lab_11.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		void FromFile(char* fname,Student & stud) // виведення файлу на екран
		{
			ifstream fin(fname, ios::binary); 
			fin.read((char*)&stud, sizeof(Student));
			fin.close();
		}

		
		TEST_METHOD(TestMethod1)
		{
			Student stud{ "онишків", 1,(Specialnists)1, 3, 4, 5 };
			Student stud2;
			ToFile(stud, 1, "proba.bin");
			FromFile("proba.bin", stud2);
			Assert::AreEqual(stud.prizv, stud2.prizv);
			Assert::AreEqual(stud.kyrs, stud2.kyrs);
			Assert::AreEqual(stud.math_grade, stud2.math_grade);
			Assert::AreEqual(stud.physics_grade, stud2.physics_grade);
			Assert::AreEqual(stud.chisel_metod_grade, stud2.chisel_metod_grade);
		}
	};
}
