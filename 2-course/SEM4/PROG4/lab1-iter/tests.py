from main import fib_gen, start, FibonacciIter, SimpleFibonacciIter
import pytest

def test_fib_gen():
    gen = start(fib_gen)()

    assert gen.send(0) == None
    assert gen.send("5") == None
    assert gen.send(5) == [0, 1, 1, 2, 3]

def test_FibonacchiIter():
    data1 = [f for f in range(0, 10)]
    data2 = [f for f in range(0, 100)]
    
    assert list(FibonacciIter(data1)) == [0, 1, 2, 3, 5, 8]
    assert list(FibonacciIter(data2)) == [0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
    
def test_SimpleFibonacciIter():
    data1 = [f for f in range(0, 10)]
    data2 = [f for f in range(0, 100)]
    
    assert list(SimpleFibonacciIter(data1)) == [0, 1, 2, 3, 5, 8]
    assert list(SimpleFibonacciIter(data2)) == [0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]

    
if __name__ == "__main__":
    pytest.main([__file__])