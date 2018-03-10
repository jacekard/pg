class Node:
    def __init__(self, val):
        self.value = val
        self.next = None
        self.prev = None

class List:
    def __init__(self):
        self.head = None
    
    def push_back(self, data):
        New = Node(data)
        if self.head is None:
            self.head = New
        else:
            tmp = self.head
            while tmp.next is not None:
                tmp = tmp.next
            tmp.next = New
            New.prev = tmp

    def push_front(self, data):
        New = Node(data)
        if self.head is None:
            self.head = New
        else:
            tmp = self.head
            tmp.prev = New
            New.next = tmp
            self.head = New

    def showAll(self):
        tmp = self.head
        while tmp is not None:
            print("{} ".format(tmp.value), end="")
            tmp = tmp.next
        print("")

    def deleteIndex(self, index):
        if index == 0 and self.head.next is None:
            self.head = None
            return
        elif index == 0 and self.head.next is not None:
            self.head.next.prev = None
            self.head = self.head.next
            return

        tmp = self.head
        for i in range(index):
            tmp = tmp.next
            if tmp is None:
                print("index out of range exception")
                return
        if tmp.next is not None:
            tmp.prev.next = tmp.next
            tmp.next.prev = tmp.prev
            tmp = None
        else:
            tmp.prev.next = None
            tmp = None



lista = List()
lista.push_back(1)
lista.push_back(2)
lista.push_back(3)
lista.push_front(0)
lista.showAll()
lista.deleteIndex(0)
lista.showAll()
lista.deleteIndex(1)
lista.showAll()
lista.push_back(4)
lista.showAll()
lista.deleteIndex(2)
lista.showAll()
lista.deleteIndex(5)
