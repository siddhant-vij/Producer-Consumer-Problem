#include <iostream>
#include <vector>
#include <thread>
#include "Producer.hpp"
#include "Consumer.hpp"

int main()
{
  const int MAX_SIZE = 5;
  MessageBuffer messageBuffer(MAX_SIZE);

  Producer producer(messageBuffer);
  Consumer consumer(messageBuffer);

  std::thread producerThread([&producer]()
                             { producer.produce(); });
  std::thread consumerThread([&consumer]()
                             { consumer.consume(); });

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  producer.stop();
  consumer.stop();

  producerThread.join();
  consumerThread.join();

  return 0;
}
