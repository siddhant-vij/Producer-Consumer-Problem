#include "Producer.hpp"
#include <iostream>
#include <random>

Producer::Producer(MessageBuffer &mb) : messageBuffer(mb) {}

void Producer::produce()
{
  while (running)
  {
    Message message(id++, rand() % 100);
    messageBuffer.offer(message);
    std::cout << "Put: " << message.getId() << std::endl;
  }
}

void Producer::operator()()
{
  produce();
}

void Producer::stop()
{
  running = false;
}
