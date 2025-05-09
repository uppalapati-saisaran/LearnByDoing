#pragma once
#include "ITask.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <sstream>
#include <iostream>

class PrimeNumberTask : public ITask {
private:
	std::atomic<bool> running;
	std::atomic<bool> paused;
	std::atomic<bool> stopped;

	std::string status;
	std::thread taskThread;
	std::mutex mtx;
	std::condition_variable cv;

	void generatePrimes() {
		std::ostringstream output;
		int num = 2;
		int count = 0;

		while (!stopped && count < 100) {
			// Pause support
			std::unique_lock<std::mutex> lock(mtx);
			cv.wait(lock, [this]() { return !paused || stopped;  });
            
			if (stopped)
				break;
			lock.unlock();

			bool isPrime = true;
			for (int i = 2; i * i <= num; ++i) {
				if (num % i == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) {
				output << num << " ";
				++count;
			}
			++num; 
		}

		status = stopped ? "Stopped" : "Completed." + output.str();
	}
public:
	PrimeNumberTask() : 
		running(false), paused(false),stopped(false),status("Initialized")
	{ }

	void execute() override {
		std::cout << "Executing PrimeNumberTask.." << std::endl;
		running = true;
		taskThread = std::thread(&PrimeNumberTask::generatePrimes, this);
		status = "Running";
	}

	void pause() override {
		paused = true;
		status = "Paused";
	}

	void resume() override {
		if (paused) {
			paused = false;
			status = "Running";
			cv.notify_one();
		}
	}

	void stop() override {
		stopped = true;
		status = "Stopping...";
		cv.notify_one();
		if (taskThread.joinable())
			taskThread.join();
	}

	std::string getStatus() const override {
		return status;
	}

	~PrimeNumberTask() {
		stop();
	}
};
