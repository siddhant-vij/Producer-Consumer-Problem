package com.prodcons;

import java.util.concurrent.atomic.AtomicInteger;

public class Producer implements Runnable {
  private volatile boolean running;
  private MessageBuffer messageBuffer;
  private AtomicInteger id;

  public Producer(MessageBuffer messageBuffer) {
    this.messageBuffer = messageBuffer;
    this.id = new AtomicInteger(0);
    this.running = true;
  }

  @Override
  public void run() {
    produce();
  }

  private void produce() {
    while (running) {
      Message message = new Message(id.getAndIncrement(), id.get());
      messageBuffer.put(message);
      System.out.println("Produced: " + message.getId());
    }
  }

  public void stop() {
    running = false;
  }
}
