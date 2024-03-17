#pragma once

#include "message_buffer.hpp"
#include <atomic>

class Consumer
{
  std::atomic<bool> running{true};
  MessageBuffer &messageBuffer;

public:
  explicit Consumer(MessageBuffer &mb);

  void consume();
  void operator()();
  void stop();
};
