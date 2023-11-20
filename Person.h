#pragma once
#include <iostream>

class Person
{
	public:
		Person();
		Person(int id, std::string name, int count);
		void setId(int id);
		void setName(std::string name);
		void setCount(int count);
		int getId(int count) const;
		std::string getName() const;
		int getCount() const;
	private:
		int id;
		std::string name;
		int count;
};

