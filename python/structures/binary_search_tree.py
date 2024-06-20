class Node:
    def __init__(self, value):
        self.value = value
        self.left: Node | None = None
        self.right: Node | None = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value) -> bool:
        node = Node(value)
        if self.root is None:
            self.root = node
            return True

        temp = self.root

        while True:
            if node.value == temp.value:
                return False

            if node.value < temp.value:
                if temp.left is None:
                    temp.left = node
                    return True
                temp = temp.left

            else:
                if temp.right is None:
                    temp.right = node
                    return True
                temp = temp.right

    def contains(self, value) -> bool:
        temp = self.root
        while temp is not None:
            if value < temp.value:
                temp = temp.left
            elif value > temp.value:
                temp = temp.right
            else:
                return True

        return False


if __name__ == "__main__":
    tree = BinarySearchTree()
    tree.insert(2)
    tree.insert(1)
    tree.insert(3)
    print(tree.root.value)
    print(tree.root.left.value)
    print(tree.root.right.value)
    print(tree.contains(3))
