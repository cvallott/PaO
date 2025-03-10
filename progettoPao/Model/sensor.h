#ifndef SENSOR_H
#define SENSOR_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QObject>
#include <QRandomGenerator>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "sensor_observer_interface.h"
#include "sensor_visitor_interface.h"

class Sensor: public QObject {
private:
    int id;
    QString name;
    QString type;
    QString environment;
    static int counter;
    int generateId() const;
    QVector<Sensor_observer_interface*> observers;
protected:
    QList<QPointF> simulationData;
public:
    Sensor(QString, QString, QString, QObject* parent = nullptr);
    virtual int getId() const;
    virtual QString getName() const;
    virtual QString getType() const;
    virtual QString getEnv() const;
    virtual QList<QPointF> getSimData() const;
    virtual QList<QString> getInfo() const;
    virtual void setName(const QString&);
    virtual void setType(const QString&);
    virtual void setEnv(const QString&);
    virtual void setSimulationData(const QList<QPointF>&);
    virtual void genSimulation() =0;
    virtual bool has_simulation_data() const;
    virtual void addObserver(Sensor_observer_interface*);
    virtual void notifyObservers(Sensor&);
    virtual void accept(SensorVisitorInterface& visitor) = 0;
    QJsonObject sensorToJsonCommonField() const;
    virtual QJsonObject sensorToJson() const =0;
    virtual ~Sensor() {}
};

#endif // SENSOR_H
