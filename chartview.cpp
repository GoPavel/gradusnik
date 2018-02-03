#include "chartview.h"
#include <QtCharts/QChartView>

ChartView::ChartView(QtCharts::QChart *chart, QWidget *parent)
    : QtCharts::QChartView(chart, parent) {

}

ChartView::ChartView(): QtCharts::QChartView() { }

void ChartView::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    default:
        QChartView::keyPressEvent(event);
        break;
    }
}
