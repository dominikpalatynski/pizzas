#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <chrono>
#include <memory>
#include "Pizza.hpp"
#include "TimeDummy.hpp"
enum class Status
{
    New,
    Paid,
    Baked,
    Completed
};

using Order = std::tuple<int, Pizzas, std::chrono::system_clock::time_point, Status>;

class Pizzeria
{
public:
    Pizzeria(std::string const & name, std::unique_ptr<TimeDelay> timeD);
    int makeOrder(Pizzas pizzas);
    double calculatePrice(int orderId);
    void bakePizzas(int orderId);
    void completeOrder(int orderId);

private:
    std::string name_;
    std::vector<Order> orders_;
    std::unique_ptr<TimeDelay> timeDelay_;
};

