#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class StopWatch : public QObject
{
    Q_OBJECT

public:
    explicit StopWatch(QObject *parent = nullptr);

    // Запуск секундомера
    void Start();

    // Остановка секундомера
    void Stop();

    // Очистка секундомера
    void Clear();

    // Количество кругов
    void countCircle();

    // Установка времени
    void setTime(float time);

    // Установка круга
    void setCircle(int circ);

    // Текущее время
    float getCurrentTime();

    // Начальное время
    float getStartTime();

    // Текущий круг
    int getCurrentCircle();

    // Проверить, запущен ли секундомер
    bool isStart();

    //Адрес qTimer
    QTimer* getQTimer();

signals:
    void sig_Start();
    void sig_Stop();
    void sig_Clear();
    void sig_Circle();

private:
    bool isStart_; // флаг работы секундомера
    float currentTime_; // текущее время
    float startTime_; // время от начала работы круга
    int currentCircle_; // текущий круг
    QTimer* qTimer;

};

#endif // STOPWATCH_H
