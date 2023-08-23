#pragma once
#include <chrono>
#include <thread>


class TimeDelay {
    public:
        virtual ~TimeDelay() = default;
        virtual void sleepFor(std::chrono::milliseconds duration) = 0;
};

class RealTimeDelay : public TimeDelay {
    public:
       
        virtual void sleepFor(std::chrono::milliseconds duration) override{
           std::this_thread::sleep_for(duration);
        };
};

class SimulatedTimeDelay : public TimeDelay {
    public:
       
        virtual void sleepFor(std::chrono::milliseconds duration) override;
};