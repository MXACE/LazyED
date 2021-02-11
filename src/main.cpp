#include "mainwindow.h"

#include "backend/backend.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	led::Configuration cfg;
	cfg.eliteDangerousJournalPath = "testdir";
	led::Backend backend(&cfg);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
