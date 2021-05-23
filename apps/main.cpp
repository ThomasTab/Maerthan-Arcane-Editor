#include <QtWidgets/QApplication>
#include <editor.h>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Editor w;
	w.show();
	w.setFixedSize(w.size()); // Disable resizing
	return a.exec();
}
