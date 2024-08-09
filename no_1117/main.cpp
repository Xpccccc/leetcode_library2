
// https://leetcode.cn/problems/building-h2o/
// 1117. H2O 生成

class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int hydrogen_count = 0; // 计数到达的氢线程数量
    int oxygen_count = 0;   // 计数到达的氧线程数量

public:
    H2O() {}

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);

        // 等待直到有少于两个氢线程和至少一个氧线程
        while (hydrogen_count == 2) {
            cv.wait(lock);
        }

        // 增加氢线程计数
        hydrogen_count++;

        // 释放氢气，输出 "H"
        releaseHydrogen();

        // 检查是否可以生成一个水分子
        if (hydrogen_count == 2 && oxygen_count == 1) {
            // 重置计数器
            hydrogen_count = 0;
            oxygen_count = 0;
            // 唤醒所有等待的线程
            cv.notify_all();
        } else {
            // 唤醒可能的氧线程
            cv.notify_one();
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);

        // 等待直到有少于一个氧线程和至少两个氢线程
        while (oxygen_count == 1 || hydrogen_count < 2) {
            cv.wait(lock);
        }

        // 增加氧线程计数
        oxygen_count++;

        // 释放氧气，输出 "O"
        releaseOxygen();

        // 检查是否可以生成一个水分子
        if (hydrogen_count == 2 && oxygen_count == 1) {
            // 重置计数器
            hydrogen_count = 0;
            oxygen_count = 0;
            // 唤醒所有等待的线程
            cv.notify_all();
        } else {
            // 唤醒可能的氢线程
            cv.notify_one();
        }
    }
};
