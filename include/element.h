#pragma once
#include <modifier.h>
#include <vector>

class Element
{
	public:
		Element();
		Element(std::string name);

		void setName(std::string name);
		std::string getName();
		void addModifier(Modifier modifier);

		std::vector<Modifier> getModifiers();

	private:
		std::string _name;
		std::vector<Modifier> _modifiers;
};