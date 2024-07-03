
// https://leetcode.cn/problems/print-in-order/
// 1114. 按序打印

class Foo {
public:
    Foo() {
        sem_init(&_semB, 0, 0);
        sem_init(&_semC, 0, 0);
    }

    ~Foo() {
        sem_destroy(&_semB);
        sem_destroy(&_semC);
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&_semB);
    }

    void second(function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&_semB);
        printSecond();
        sem_post(&_semC);
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&_semC);
        printThird();
    }

private:
    sem_t _semB;
    sem_t _semC;
};