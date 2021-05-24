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

std::string Element::getName()
{
	return _name;
}

void Element::addModifier(Modifier modifier)
{
	_modifiers.push_back(modifier);
}

std::vector<Modifier> Element::getModifiers()
{
	return _modifiers;
}
