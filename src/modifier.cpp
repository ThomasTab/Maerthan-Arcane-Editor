#include <modifier.h>

Modifier::Modifier()
{
	_name = "undefined";
}

Modifier::Modifier(std::string name)
{
	_name = name;
}

void Modifier::setName(const std::string name)
{
	_name = name;
}

void Modifier::addAttribute(int masteryLevel, std::vector<int> attributes)
{
	_attributes[masteryLevel] = attributes;
}

void Modifier::addCost(int masteryLevel, std::vector<int> costs)
{
	_costs[masteryLevel] = costs;
}

void Modifier::setCostOperator(std::function<int(int, int)> operation)
{
	_costOperator = operation;
}

std::string Modifier::getName()
{
	return _name;
}

std::vector<int> Modifier::getAttributes(int masteryLevel)
{
	return(_attributes[masteryLevel]);
}

std::vector<int> Modifier::getCosts(int masteryLevel)
{
	return(_costs[masteryLevel]);
}

const std::function<int(int, int)> Modifier::getCostOperator()
{
	return _costOperator;
}
