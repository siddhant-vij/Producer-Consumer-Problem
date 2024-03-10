package com.prodcons;

import java.util.List;

public class Main {
  private static final int MAX_SIZE = 5;

  public static void main(String[] args) throws InterruptedException {
    MessageBuffer messageBuffer = new MessageBuffer(MAX_SIZE);

    Producer producer = new Producer(messageBuffer);
    Thread producerThread = new Thread(producer);

    Consumer consumer = new Consumer(messageBuffer);
    Thread consumerThread = new Thread(consumer);

    List<Thread> threads = List.of(producerThread, consumerThread);
    threads.forEach(Thread::start);

    Thread.sleep(2000);

    producer.stop();
    consumer.stop();

    threads.forEach(thread -> {
      try {
        thread.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    });

    System.out.println("Main thread finished after 2 seconds.");
  }
}
