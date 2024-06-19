class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Queue:
    def __init__(self, value):
        node = Node(value)
        self.first = node
        self.last = node
        self.length = 1

    def enqueue(self, value):
        node = Node(value)
        if self.length == 0:
            self.first = node
            self.last = node
        else:
            self.last.next = node
            self.last = node
        self.length += 1

    def deque(self) -> Node | None:
        if self.length == 0:
            return None

        temp = self.first

        if self.length == 1:
            self.first = None
            self.last = None
        else:
            self.first = self.first.next
            temp.next = None

        self.length -= 1
        return temp

    def print(self):
        temp = self.first
        while temp is not None:
            print(temp.value)
            temp = temp.next


if __name__ == "__main__":
    queue = Queue(1)
    queue.enqueue(2)
    queue.enqueue(3)

    queue.print()
    for _ in range(4):
        temp = queue.deque()
        print(temp)
