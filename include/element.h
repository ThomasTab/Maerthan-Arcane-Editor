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

	private:
		std::string _name;
		std::vector<Modifier> _modifiers;
};