class Message(object):

    def __init__(self, id: int, value: str) -> None:
        self._id = id
        self._value = value

    @property
    def id(self) -> int:
        return self._id

    @property
    def value(self) -> str:
        return self._value
