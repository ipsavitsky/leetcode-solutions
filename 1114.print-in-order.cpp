/**
 * @file 1114.print-in-order.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/print-in-order/
 * @version 0.1
 * @date 2023-09-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <array>
#include <functional>
#include <mutex>

class Foo {
  private:
    std::array<std::mutex, 2> mutexes;

  public:
    Foo() {
        mutexes[0].lock();
        mutexes[1].lock();
    }

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mutexes[0].unlock();
    }

    void second(std::function<void()> printSecond) {
        mutexes[0].lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mutexes[1].unlock();
    }

    void third(std::function<void()> printThird) {
        mutexes[1].lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
