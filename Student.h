#pragma once

#include<iostream>
#include<string>

using namespace std;

struct Student
{
	string name;
	int score;
	
	bool operator<(const Student &otherStudent)
	{
		return this->score < otherStudent.score;
	}

	friend ostream& operator<<(ostream& os,const Student& Student)
	{
		os << "Student:" << Student.name << " " << Student.score << endl;
		return os;
	}
};

