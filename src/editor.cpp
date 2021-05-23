#include <editor.h>

Editor::Editor(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	loadConfig("settings.json");
}

void Editor::loadConfig(std::string configPath) {
    using json = nlohmann::json;

    // Read json config
    json jsonSource;
    std::ifstream file;
    file.open(configPath);
    file >> jsonSource;

    // Loop over each element in json
    for (int elem = 0; elem < jsonSource["Elements"].size(); elem++) {

        Element tempElem;
        tempElem.setName(jsonSource["Elements"][elem].value("Name", "Unreadable"));

        // Loop over each modifier in element
        for (int mod = 0; mod < jsonSource["Elements"][elem]["Modifiers"].size(); mod++) {

            Modifier modifier(jsonSource["Elements"][elem]["Modifiers"][mod].value("Name", "Unreadable"));

            // Loop over each mastery level (3 max)
            for (int mLevel = 0; mLevel < 3; mLevel++) {

                std::vector<int> attributes = jsonSource["Elements"][elem]["Modifiers"][mod]["Attribute"][mLevel].get<std::vector<int>>();
                std::vector<int> costs = jsonSource["Elements"][elem]["Modifiers"][mod]["Cost"][mLevel].get<std::vector<int>>();

                if (jsonSource["Elements"][elem]["Modifiers"][mod]["CostType"].get<std::string>() == "multiple") {
                    modifier.setCostOperator(std::multiplies<int>());
                }
                else {
                    modifier.setCostOperator(std::plus<int>());
                }

                modifier.addAttribute(mLevel, attributes);
                modifier.addCost(mLevel, costs);
            }
            tempElem.addModifier(modifier);
        }

        elements.push_back(tempElem);
    }
}