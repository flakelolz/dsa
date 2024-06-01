type Node<T> = {
    value: T;
    next?: Node<T>;
};
export default class Queue<T> {
    public length: number;
    private head?: Node<T>;
    private tail?: Node<T>;

    constructor() {
        this.head = this.tail = undefined;
        this.length = 0;
    }

    enqueue(item: T): void {
        const node = { value: item } as Node<T>;

        this.length += 1;

        if (this.length === 1) {
            this.tail = this.head?.next;
        }

        if (!this.tail) {
            this.tail = this.head = node;
            return;
        }

        this.tail.next = node;
        this.tail = node;
    }

    deque(): T | undefined {
        // Check undefined
        if (!this.head) {
            return undefined;
        }

        // Book-keeping
        this.length -= 1;

        // Detach
        const head = this.head;
        this.head = this.head.next;

        // Cleanup
        head.next = undefined;

        if (this.length === 0) {
            this.tail == undefined;
        }

        // Value
        return head.value;
    }

    peek(): T | undefined {
        return this.head?.value;
    }
}
