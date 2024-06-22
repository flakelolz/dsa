class HashTable:
    def __init__(self, size=7):
        self.data_map = [None] * size

    def __hash(self, key) -> int:
        my_hash = 0
        for letter in key:
            my_hash = (my_hash + ord(letter) * 23) % len(self.data_map)

        return my_hash

    def set_item(self, key, value):
        index = self.__hash(key)

        if self.data_map[index] is None:
            self.data_map[index] = []

        self.data_map[index].append([key, value])

    def get(self, key) -> int | None:
        index = self.__hash(key)

        if self.data_map[index] is not None:
            for pair in self.data_map[index]:
                if pair[0] == key:
                    return pair[1]
        return None

    def keys(self):
        keys = []
        for addr in self.data_map:
            if addr is not None:
                for key in addr:
                    keys.append(key[0])

        return keys

    def print(self):
        for i, val in enumerate(self.data_map):
            print(i, ":", val)


if __name__ == "__main__":
    table = HashTable()
    table.set_item("bolts", 1400)
    table.set_item("washers", 50)
    table.print()
    print(table.get("bolts"))
    print(table.get("lumber"))
    print(table.keys())
