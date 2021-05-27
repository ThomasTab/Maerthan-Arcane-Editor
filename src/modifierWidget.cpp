#include <modifierWidget.h>

ModifierWidget::ModifierWidget(Modifier modifier, int masteryLevel, QWidget* parent) : QWidget(parent) {
	_ui.setupUi(this);
	_modifier = modifier;
	_masteryLevel = masteryLevel;
	_cost = 0;
	_ui.labelModifierName->setText(QString::fromStdString(_modifier.getName()));
	connect(&_radioGroup, SIGNAL(buttonClicked(int)), this, SLOT(onRadioButtonClicked()));

	refreshDisplay();
}

int ModifierWidget::getCurrentCost(){
	return _cost;
}

Modifier ModifierWidget::getModifier(){
	return _modifier;
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

void ModifierWidget::refreshDisplay() {
	// Remove previous radiobuttons
	clearLayout(_ui.verticalLayoutAttributes);
	_radioButtons.clear(); // WARNING, MEMORY LEAKS AS WE DON'T DELETE POINTERS

	for (int i = 0; i < _modifier.getAttributes(_masteryLevel).size(); i++) {
		QRadioButton* attribute = new QRadioButton(QString::fromStdString(std::to_string(_modifier.getAttributes(_masteryLevel)[i])), this);
		_radioButtons.push_back(attribute);
		_ui.verticalLayoutAttributes->addWidget(attribute);
		_radioGroup.addButton(attribute,i);
	}

	_radioButtons[0]->setChecked(true);
	onRadioButtonClicked();
}

void ModifierWidget::paintEvent(QPaintEvent* event) {
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	QWidget::paintEvent(event);
	// Resize label to center text correctly
	_ui.labelModifierName->setFixedWidth(this->size().width());
}

void ModifierWidget::onRadioButtonClicked() {
	int radioButtonId = _radioGroup.checkedId();
	_cost = _modifier.getCosts(_masteryLevel)[radioButtonId];
	emit costChanged();
}

void ModifierWidget::onMasteryLevelChanged(int masteryLevel) {
	_masteryLevel = masteryLevel;
	refreshDisplay();
}
