#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include "mocks/PizzaMock.hpp"
#include "Pizzeria.hpp"
#include "Margherita.hpp"
#include "Funghi.hpp"
#include "TimeDummy.hpp"

using namespace std;
using namespace ::testing;

struct PizzeriaTest : public ::testing::Test
{
public:
    std::unique_ptr<SimulatedTimeDelay> timeDelay = std::make_unique<SimulatedTimeDelay>();
    Pizzeria pizzeria = Pizzeria("dummyName",std::move(timeDelay)); 
};


TEST_F(PizzeriaTest, priceForMargherita25AndFunghi30ShouldBe55)
{
    // Given
    Pizzas pizzas = {new Margherita{25.0}, new Funghi{30.0}};

    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    auto price = pizzeria.calculatePrice(orderId);

    // Then
    ASSERT_EQ(55, price);
}

// TEST_F(PizzeriaTest, bakeDummyPizza)
// {
//     // Given
//     Pizzas pizzas = {new PizzaDummy{}};

//     // When
//     auto orderId = pizzeria.makeOrder(pizzas);
//     pizzeria.bakePizzas(orderId);
// }

// TEST_F(PizzeriaTest, completeOrderWithStubPizza)
// {
//     // Given
//     Pizzas pizzas = {new PizzaStub{"STUB"}};

//     // When
//     auto orderId = pizzeria.makeOrder(pizzas);
//     pizzeria.bakePizzas(orderId);
//     pizzeria.completeOrder(orderId);
// }

TEST_F(PizzeriaTest, calculatePriceForPizzaMock)
{   
    // Given
    auto mock = std::make_unique<PizzaMock>();
    Pizzas pizzas = {mock.get()}; // Get the raw pointer from unique_ptr
    EXPECT_CALL(*mock, getPrice())
        .WillOnce(testing::Return(40)); // Set the expected return value
    
    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    auto price = pizzeria.calculatePrice(orderId);
   
    // Then
    ASSERT_EQ(40, price);
}