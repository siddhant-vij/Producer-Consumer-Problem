import queue
import random
import time

from message import Message


class MessageBuffer:
    def __init__(self, capacity: int):
        self._capacity = capacity
        self._buffer = queue.Queue(maxsize=capacity)

    @property
    def capacity(self) -> int:
        return self._capacity

    @property
    def is_empty(self) -> bool:
        return self._buffer.empty()

    @property
    def is_full(self) -> bool:
        return self._buffer.full()

    def put(self, message: Message) -> None:
        self._buffer.put(message)
        time.sleep(random.random() * 100 / 1000)

    def take(self) -> Message:
        message = self._buffer.get()
        time.sleep(random.random() * 100 / 1000)
        return message

