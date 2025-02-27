#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent)
    : QObject{parent}
{
    isStart_ = false;
    currentTime_ = 0;
    startTime_ = 0;
    currentCircle_ = 1;
    qTimer = new QTimer(this);
}

void StopWatch::Start()
{
    isStart_ = true;
    qTimer->start(100);
    emit sig_Start();
}

void StopWatch::Stop()
{
    isStart_ = false;
    qTimer->stop();
    emit sig_Stop();
}

void StopWatch::Clear()
{
    currentTime_ = 0;
    startTime_ = 0;
    currentCircle_ = 1;
    emit sig_Clear();
}

void StopWatch::countCircle()
{
    emit sig_Circle();
}

void StopWatch::setTime(float time)
{
    currentTime_ = time;
}

void StopWatch::setCircle(int circ)
{
    currentCircle_ = circ;
}

float StopWatch::getCurrentTime()
{
    return currentTime_;
}

float StopWatch::getStartTime()
{
    return startTime_;
}

int StopWatch::getCurrentCircle()
{
    startTime_ = currentTime_;
    return currentCircle_;
}

bool StopWatch::isStart()
{
    return isStart_;
}

QTimer *StopWatch::getQTimer()
{
    return qTimer;
}

