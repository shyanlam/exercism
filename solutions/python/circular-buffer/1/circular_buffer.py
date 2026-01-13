class BufferFullException(BufferError):
    """Exception raised when CircularBuffer is full.

    message: explanation of the error.

    """
    def __init__(self, message):
        self.message = message


class BufferEmptyException(BufferError):
    """Exception raised when CircularBuffer is empty.

    message: explanation of the error.

    """
    def __init__(self, message):
        self.message = message


class CircularBuffer:
    #     ↓read
    # [ ][ ][ ][ ][ ][ ][ ][ ][ ]
    #     ↑write
    #
    def __init__(self, capacity):
        self._capacity = capacity
        self._buffer = [None] * self._capacity
        self._read_index = 0
        self._write_index = 0

    def _is_buffer_full(self):
        return self._read_index == self._write_index and self._buffer[self._read_index] is not None

    def _is_buffer_empty(self):
        return self._read_index == self._write_index and self._buffer[self._read_index] is None

    def _advance_read_index(self):
        self._read_index = (self._read_index + 1) % self._capacity

    def _advance_write_index(self):
        self._write_index = (self._write_index + 1) % self._capacity

    def read(self):
        if self._is_buffer_empty():
            raise BufferEmptyException("Circular buffer is empty")
        else:
            val = self._buffer[self._read_index]
            self._buffer[self._read_index] = None
            self._advance_read_index()
            return val

    def write(self, data):
        if self._is_buffer_full():
            raise BufferFullException("Circular buffer is full")
        else:
            assert(self._buffer[self._write_index] is None)
            self._buffer[self._write_index] = data
            self._advance_write_index()

    def overwrite(self, data):
        self._buffer[self._write_index] = data
        if self._is_buffer_full():
            self._advance_read_index()
        self._advance_write_index()

    def clear(self):
        self._buffer[0:] = [None] * self._capacity
        self._read_index = self._write_index = 0

