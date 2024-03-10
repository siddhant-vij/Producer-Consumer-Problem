package com.prodcons;

public class Consumer implements Runnable {
  private volatile boolean running;
  private MessageBuffer messageBuffer;

  public Consumer(MessageBuffer messageBuffer) {
    this.messageBuffer = messageBuffer;
    this.running = true;
  }

  @Override
  public void run() {
    consume();
  }

  private void consume() {
    while (running) {
      Message message = messageBuffer.take();
      System.out.println("Consumed: " + message.getId());
    }
  }

  public void stop() {
    running = false;
  }
}
