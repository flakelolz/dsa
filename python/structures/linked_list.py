class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
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
            self.tail = node
        self.length += 1

        return True

    def pop(self) -> Node | None:
        if self.length == 0:
            return None

        temp = self.head
        prev = self.head

        while temp.next:
            prev = temp
            temp = temp.next

        if self.length == 1:
            self.head = None
            self.tail = None
        else:
            self.tail = prev
            self.tail.next = None
        self.length -= 1

        return temp

    def prepend(self, value) -> bool:
        node = Node(value)
        if self.length == 0:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
        self.length += 1

        return True

    def pop_first(self) -> Node | None:
        if self.length == 0:
            return None

        temp = self.head

        if self.length == 1:
            self.tail = None
        else:
            self.head = self.head.next
            temp.next = None
        self.length -= 1

        return temp

    def get(self, index) -> Node | None:
        if index < 0 or index >= self.length:
            return None

        temp = self.head

        for _ in range(index):
            temp = temp.next

        return temp

    def set_value(self, index, value) -> bool | None:
        temp = self.get(index)

        if temp is not None:
            temp.value = value

        return True

    def insert(self, index, value) -> bool:
        if index < 0 or index > self.length:
            return False

        if index == 0:
            return self.prepend(value)

        if index == self.length:
            return self.append(value)

        node = Node(value)
        temp = self.get(index - 1)
        node.next = temp.next
        temp.next = node

        return True

    def remove(self, index) -> Node | None:
        if index < 0 or index >= self.length:
            return None

        if index == 0:
            return self.pop_first()

        if index == self.length - 1:
            return self.pop()

        prev = self.get(index - 1)
        temp = prev.next
        prev.next = temp.next
        temp.next = None
        self.length -= 1

        return temp

    def reverse(self):
        temp = self.head
        self.head = self.tail
        self.tail = temp

        after = temp.next
        before = None

        for _ in range(self.length):
            after = temp.next
            temp.next = before
            before = temp
            temp = after

    def print(self):
        temp = self.head
        while temp is not None:
            print(temp.value)
            temp = temp.next


if __name__ == "__main__":
    list = LinkedList(0)
    list.append(1)
    list.append(2)
    list.append(3)
    list.insert(4, 4)
    list.reverse()

    list.print()
