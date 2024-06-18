class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None


class DoubleLinkedList:
    def __init__(self, value):
        node = Node(value)
        self.head = node
        self.tail = node
        self.length = 1

    def append(self, value) -> bool:
        node = Node(value)
        if self.length == 0:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node

        self.length += 1
        return True

    def pop(self) -> Node | None:
        temp = self.tail

        if self.length == 0:
            return None

        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
            temp.prev = None

        self.length -= 1
        return temp

    def prepend(self, value) -> bool:
        node = Node(value)

        if self.length == 0:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

        self.length += 1
        return True

    def pop_first(self) -> Node | None:
        if self.length == 0:
            return None

        temp = self.head

        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
            temp.next = None

        self.length -= 1
        return temp

    def get(self, index) -> Node | None:
        if index < 0 or index >= self.length:
            return None

        temp = self.head
        if index < self.length // 2:
            for _ in range(index):
                temp = temp.next
        else:
            temp = self.tail
            for _ in range(self.length - 1, index, -1):
                temp = temp.prev

        return temp

    def set_value(self, index, value) -> bool:
        if index < 0 or index >= self.length:
            return False

        temp = self.get(index)

        if temp is not None:
            temp.value = value
            return True

        return False

    def insert(self, index, value) -> bool:
        if index < 0 or index > self.length:
            return False

        if index == 0:
            return self.prepend(value)

        if index == self.length:
            return self.append(value)

        node = Node(value)
        before = self.get(index - 1)
        after = before.next

        node.prev = before
        node.next = after
        before.next = node
        after.prev = node

        self.length += 1
        return True

    def remove(self, index):
        if index < 0 or index >= self.length:
            return False

        if index == 0:
            return self.pop_first()

        if index == self.length - 1:
            return self.pop()

        temp = self.get(index)
        temp.next.prev = temp.prev
        temp.prev.next = temp.next
        temp.next = None
        temp.prev = None

        self.length -= 1
        return temp

    def print(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next


if __name__ == "__main__":
    list = DoubleLinkedList(11)
    list.append(3)
    list.append(23)
    list.append(7)
    list.print()
