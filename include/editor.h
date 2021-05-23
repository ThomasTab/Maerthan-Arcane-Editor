#include <QtWidgets/QMainWindow>
#include <QtWidgets/QComboBox>
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <element.h>
#include "ui_editor.h"
#include <vector>

class Editor : public QMainWindow
{
	Q_OBJECT

public:
	Editor(QWidget* parent = Q_NULLPTR);

private:
	Ui::EditorClass ui;
	std::vector<Element> elements;
	void loadConfig(std::string configPath);

};
