#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChart>

class Chart: public QtCharts::QChart{
public:
    explicit Chart(QGraphicsItem *parent = 0, Qt::WindowFlags = 0);
    ~Chart();

};

#endif // CHART_H
