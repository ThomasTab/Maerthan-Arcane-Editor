#pragma once

#include <QtWidgets>
#include <modifier.h>
#include <ui_modifierWidget.h>

class ModifierWidget : public QWidget
{
    Q_OBJECT
    public:
        ModifierWidget(Modifier modifier, int masteryLevel, QWidget* parent = Q_NULLPTR);

    private:
        Ui::ModifierWidget _ui;
        Modifier _modifier;
        int _masteryLevel;

        void clearLayout(QLayout* layout);
        void refreshDisplay();


    signals:
        void costChanged();

    public slots:
        void onMasteryLevelChanged(int masteryLevel);
};