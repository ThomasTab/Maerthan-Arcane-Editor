#pragma once
#include <functional>
#include <string>
#include <vector>

class Modifier
{
	public:
		Modifier();
		Modifier(const std::string name);

		void setName(const std::string name);
		void addAttribute(int masteryLevel, std::vector<int> attributes);
		void addCost(int masteryLevel, std::vector<int> costs);
		void setCostOperator(const std::function<int(int, int)> operation);

		std::string getName();
		std::vector<int> getAttributes(int masteryLevel);
		std::vector<int> getCosts(int masteryLevel);
		const std::function<int(int, int)> getCostOperator();

	private:
		std::string _name;
		std::vector<int> _attributes[3];
		std::vector<int> _costs[3];
		std::function<int(int, int)> _costOperator;
};