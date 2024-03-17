#pragma once

#include "message_buffer.hpp"
#include <atomic>

class Producer
{
private:
  std::atomic<bool> running{true};
  MessageBuffer &messageBuffer;
  std::atomic<int> id{1};

public:
  explicit Producer(MessageBuffer &mb);

  void produce();
  void operator()();
  void stop();
};
