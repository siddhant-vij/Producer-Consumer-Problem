package com.prodcons;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ArrayBlockingQueue;

public class MessageBuffer {
  private final BlockingQueue<Message> buffer;
  private final int capacity;

  public MessageBuffer(int capacity) {
    this.capacity = capacity;
    this.buffer = new ArrayBlockingQueue<>(capacity);
  }

  public boolean isEmpty() {
    return buffer.size() == 0;
  }

  public boolean isFull() {
    return buffer.size() == capacity;
  }

  public void put(Message message) {
    try {
      buffer.put(message);
      Thread.sleep((long) (100 * Math.random()));
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
  }

  public Message take() {
    try {
      Message message = buffer.take();
      Thread.sleep((long) (100 * Math.random()));
      return message;
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    return null;
  }
}
