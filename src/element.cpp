#include <element.h>

Element::Element()
{
	_name = "undefined";
}

Element::Element(std::string name)
{
	_name = name;
}

void Element::setName(std::string name)
{
	_name = name;
}

void Element::addModifier(Modifier modifier)
{
	_modifiers.push_back(modifier);
}

void Element::setOverloads(std::vector<int> overloads)
{
	_overloads = overloads;
}

std::string Element::getName()
{
	return _name;
}

std::vector<Modifier> Element::getModifiers()
{
	return _modifiers;
}

std::vector<int> Element::getOverloads()
{
	return _overloads;
}