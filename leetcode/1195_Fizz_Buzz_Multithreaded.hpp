#include "../base/icode.hpp"
class FizzBuzz : public icode {
private:
    int n;
    int index;
    std::mutex mtx;

public:
    FizzBuzz() {
        this->n = 15;
        this->index = 1;
    }

    FizzBuzz(int n) {
        this->n = n;
        this->index = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (this->index <= this->n) {
            mtx.lock();
            if (this->index <= this->n && this->index%3 == 0 && this->index%5 != 0) {
                printFizz();
                this->index++;
            }
            mtx.unlock();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (this->index <= this->n) {
            mtx.lock();
            if (this->index <= this->n && this->index%3 != 0 && this->index%5 == 0) {
                printBuzz();
                this->index++;
            }
            mtx.unlock();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (this->index <= this->n) {
            mtx.lock();
            if (this->index <= this->n && this->index%3 == 0 && this->index%5 == 0) {
                printFizzBuzz();
                this->index++;
            }
            mtx.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (this->index <= this->n) {
            mtx.lock();
            while (this->index <= this->n && this->index%3 != 0 && this->index%5 != 0) {
                printNumber(this->index);
                this->index++;
            }
            mtx.unlock();
        }
    }

    void run(){

    }
};