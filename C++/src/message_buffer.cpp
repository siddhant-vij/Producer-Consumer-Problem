#include <message_buffer.hpp>

MessageBuffer::MessageBuffer(size_t maxSize) : maxSize(maxSize) {}

void MessageBuffer::offer(const Message &message)
{
  std::unique_lock<std::mutex> lock(mtx);
  notFull.wait(lock, [this]
               { return buffer.size() < maxSize; });
  buffer.push(message);
  notEmpty.notify_all();
}

Message MessageBuffer::poll()
{
  std::unique_lock<std::mutex> lock(mtx);
  notEmpty.wait(lock, [this]
                { return !buffer.empty(); });
  Message message = buffer.front();
  buffer.pop();
  notFull.notify_all();
  return message;
}

bool MessageBuffer::isEmpty() const
{
  return buffer.empty();
}

bool MessageBuffer::isFull() const
{
  return buffer.size() == maxSize;
}
