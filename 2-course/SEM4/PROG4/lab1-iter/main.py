from math import sqrt
import functools


def is_sqrt(n):
    """
    Проверка - является ли число квадратом?

    Принимает число -> находит корень -> округляет

    если полученное число в квадрате == исходному -> True иначе -> False
    """

    sqrt_n = round(sqrt(n))
    if sqrt_n * sqrt_n == n:
        return True
    else:
        return False


def fib_gen():
    """
    Сопрограмма генерирует ряд фибоначи

    Реализована через 1 yield чтобы можно было делать send подряд

    """

    res = None

    while True:
        num = yield res
        res = []
        a = 0
        b = 1
        while num > 0:
            res.append(a)
            c = a + b
            a = b
            b = c
            num -= 1


def start(g):
    @functools.wraps(g)
    def inner(*args, **kwargs):
        gen = g(*args, **kwargs)
        gen.send(None)
        return gen

    return inner


class FibonacciIter:
    """
    Итератор по числам фибоначи

    При инициализации принимает collection и создает два свойства, одно для коллекции и одно для индекса

    __iter__ : возвращает ссылку на экземпляр объекта

    __next__ : берет элемент с индексом self.idx -> проверяет больше ли он 0 -> проверяет входит ли в ряд фибоначи -> при исчерпании индексов поднимается StopIteration
    """

    def __init__(self, data):
        self.data = data
        self.idx = 0

    def __iter__(self):
        return self

    def __next__(self):
        while True:
            try:
                n = self.data[self.idx]
            except IndexError:
                raise StopIteration

            if n < 0:
                self.idx += 1

            elif is_sqrt(5 * n**2 + 4) or is_sqrt(5 * n**2 - 4):
                self.idx += 1
                return n

            self.idx += 1


class SimpleFibonacciIter:
    """
    Простой итератор по числам фибоначи

    При инициализации принимает collection и создает list в переменной self.data в который записывает подходящие элементы

    __getitem__ : пробует получить элемент из self.data если успешно возвращает, если нет то поднимает IndexError
    """

    def __init__(self, data):
        self.data = [
            n for n in data if (is_sqrt(5 * n**2 - 4) or is_sqrt(5 * n**2 + 4))
        ]

    def __getitem__(self, idx):
        try:
            n = self.data[idx]
            return n
        except IndexError:
            raise IndexError
