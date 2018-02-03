#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QLineSeries>
#include "dialogopenfile.h"
#include "chartview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    ChartView* chartView;

public:
    MainWindow(QWidget *parent = 0);

public slots:
    void readFileAndDrawChart(QString path);
    void openDialogOpenFile();
};

#endif // MAINWINDOW_H
