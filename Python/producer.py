from message import Message
from message_buffer import MessageBuffer


class Producer:
    def __init__(self, message_buffer: MessageBuffer):
        self._message_buffer = message_buffer
        self._id = 0
        self._running = True

    def run(self) -> None:
        self._produce()

    def _produce(self) -> None:
        while self._running:
            message: Message = self._create_message(self._id)
            self._message_buffer.put(message)
            print(f"Produced: {message.id}")
            self._id += 1

    def _create_message(self, id: int) -> Message:
        return Message(id, str(id))

    def stop(self) -> None:
        self._running = False

