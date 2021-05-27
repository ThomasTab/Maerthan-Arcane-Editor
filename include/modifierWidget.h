#pragma once

#include <QtWidgets>
#include <modifier.h>
#include <ui_modifierWidget.h>

class ModifierWidget : public QWidget
{
    Q_OBJECT
    public:
        ModifierWidget(Modifier modifier, int masteryLevel, QWidget* parent = Q_NULLPTR);
        int getCurrentCost();
        Modifier getModifier();

    private:
        Ui::ModifierWidget _ui;
        Modifier _modifier;
        int _masteryLevel;
        int _cost;
        std::vector<QRadioButton*> _radioButtons;
        QButtonGroup _radioGroup;

        void clearLayout(QLayout* layout);
        void refreshDisplay();
        void paintEvent(QPaintEvent* event);


    signals:
        void costChanged();

    public slots:
        void onRadioButtonClicked();
        void onMasteryLevelChanged(int masteryLevel);
};