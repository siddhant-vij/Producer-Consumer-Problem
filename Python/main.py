import threading
import time

from message_buffer import MessageBuffer
from producer import Producer
from consumer import Consumer


MAX_SIZE = 5


def run() -> None:
    message_buffer = MessageBuffer(MAX_SIZE)

    producer = Producer(message_buffer)
    consumer = Consumer(message_buffer)

    producer_thread = threading.Thread(target=producer.run)
    consumer_thread = threading.Thread(target=consumer.run)

    producer_thread.start()
    consumer_thread.start()

    time.sleep(2)

    producer.stop()
    consumer.stop()

    producer_thread.join()
    consumer_thread.join()

    print("Main thread finished after 2 seconds.")


if __name__ == "__main__":
    run()
