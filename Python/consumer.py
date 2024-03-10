from message import Message
from message_buffer import MessageBuffer


class Consumer:
    def __init__(self, message_buffer: MessageBuffer):
        self._message_buffer = message_buffer
        self._running = True

    def run(self) -> None:
        self._consume()

    def _consume(self) -> None:
        while self._running:
            message: Message = self._message_buffer.take()
            print(f"Consumed: {message.id}")

    def stop(self) -> None:
        self._running = False

