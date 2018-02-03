#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartView>


class ChartView: public QtCharts::QChartView {
public:
    ChartView(QtCharts::QChart *chart, QWidget *parent = 0);

    ChartView();

protected:

    void keyPressEvent(QKeyEvent *event) override;
};

#endif // CHARTVIEW_H
