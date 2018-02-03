#include "mainwindow.h"
#include "chart.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QtCharts/QLineSeries>
#include <QtGlobal>
#include <QtCore/QtMath>
#include <chartview.h>
#define MAX_REAL qreal(-200000)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // <members>
        chartView = new ChartView();

    // <menu and actions>
        QMenu* menuEdit = menuBar()->addMenu("Edit");

        QAction* printFile = new QAction(tr("Print chart"), this);

        menuEdit->addAction(printFile);

    // set default chart
        QtCharts::QLineSeries *def_series = new QtCharts::QLineSeries();
        for (int i = 0; i < 1000; ++i) {
            def_series->append(i, i*qSin(i));
        }

        Chart *chart = new Chart();
        chart->addSeries(def_series);
        chart->setTitle("Example chart");
        chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
        chart->legend()->hide();
        chart->createDefaultAxes();

        chartView->setChart(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

    // <connect>
        connect(printFile, SIGNAL(triggered()), this, SLOT(openDialogOpenFile()));

    setCentralWidget(chartView);
}

void MainWindow::openDialogOpenFile() {
    DialogOpenFile* dialog = new DialogOpenFile();

    connect(dialog, SIGNAL(sendingPath(QString)), this, SLOT(readFileAndDrawChart(QString)));

    dialog->exec();
}

void MainWindow::readFileAndDrawChart(QString path) {
    QFile* file = new QFile(path);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(file);
    QtCharts::QLineSeries* values = new QtCharts::QLineSeries();
    for (qreal x, x_old = MAX_REAL, y; !stream.atEnd(); ) {
        stream >> x >> y;
        if (x_old < x) {
            values->append(x, y);
            x_old = x;
        }
    }
    //<setting chart>
    Chart *chart = new Chart();
    chart->legend()->hide();
    chart->addSeries(values);
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
    chart->setTitle("<b>Chart: </b>" + path);
    chart->createDefaultAxes();
    //</setting chart>

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    file->close();
}
