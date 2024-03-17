#pragma once

#include "Message.hpp"
#include <queue>
#include <mutex>
#include <condition_variable>

class MessageBuffer
{
private:
  std::queue<Message> buffer;
  const size_t maxSize;
  std::mutex mtx;
  std::condition_variable notEmpty;
  std::condition_variable notFull;

public:
  explicit MessageBuffer(size_t maxSize);

  void offer(const Message &message);
  Message poll();

  [[nodiscard]] bool isEmpty() const;
  [[nodiscard]] bool isFull() const;
};
