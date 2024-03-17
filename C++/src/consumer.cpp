#include "Consumer.hpp"
#include <iostream>

Consumer::Consumer(MessageBuffer &mb) : messageBuffer(mb) {}

void Consumer::consume()
{
  while (running)
  {
    Message message = messageBuffer.poll();
    std::cout << "Got: " << message.getId() << std::endl;
  }
}

void Consumer::operator()()
{
  consume();
}

void Consumer::stop()
{
  running = false;
}
