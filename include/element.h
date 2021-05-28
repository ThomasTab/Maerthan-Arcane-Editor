#pragma once
#include <modifier.h>
#include <vector>

class Element
{
	public:
		Element();
		Element(std::string name);

		void setName(std::string name);
		void addModifier(Modifier modifier);
		void setOverloads(std::vector<int> overloads);

		std::string getName();
		std::vector<Modifier> getModifiers();
		std::vector<int> getOverloads();

	private:
		std::string _name;
		std::vector<Modifier> _modifiers;
		std::vector<int> _overloads;
};