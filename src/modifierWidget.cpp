#include <modifierWidget.h>

ModifierWidget::ModifierWidget(Modifier modifier, int masteryLevel, QWidget* parent) : QWidget(parent) {
	_ui.setupUi(this);
	_modifier = modifier;
	_masteryLevel = masteryLevel;
	_ui.labelModifierName->setText(QString::fromStdString(_modifier.getName()));
	refreshDisplay();
}

void ModifierWidget::clearLayout(QLayout* layout) {
	QLayoutItem* item;
	while ((item = layout->takeAt(0))) {
		if (item->layout()) {
			clearLayout(item->layout());
			delete item->layout();
		}
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}
}

void ModifierWidget::refreshDisplay()
{
	clearLayout(_ui.verticalLayoutAttributes);
	for (int i = 0; i < _modifier.getAttributes(_masteryLevel).size(); i++) {
		QRadioButton* attribute = new QRadioButton(QString::fromStdString(std::to_string(_modifier.getAttributes(_masteryLevel)[i])), this);
		_ui.verticalLayoutAttributes->addWidget(attribute);
	}
}

void ModifierWidget::onMasteryLevelChanged(int masteryLevel) {
	_masteryLevel = masteryLevel;
	refreshDisplay();
}
