class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack:
    def __init__(self, value):
        node = Node(value)
        self.top = node
        self.height = 1

    def push(self, value):
        node = Node(value)
        if self.height == 0:
            self.top = node
        else:
            node.next = self.top
            self.top = node

        self.height += 1

    def pop(self) -> Node | None:
        if self.height == 0:
            return None

        temp = self.top

        self.top = self.top.next
        temp.next = None

        self.height -= 1
        return temp

    def print(self):
        temp = self.top
        while temp is not None:
            print(temp.value)
            temp = temp.next


if __name__ == "__main__":
    stack = Stack(2)
    stack.push(1)

    stack.print()
