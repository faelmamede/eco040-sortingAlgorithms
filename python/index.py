from sortFunctions.bubble import bubble
from sortFunctions.selection import selection
from sortFunctions.insertion import insertion
from sortFunctions.shell import shell
from sortFunctions.merge import merge
from sortFunctions.quick import quick

print("\nReading file...")
f = open("../assets/1000000numeros.txt", "r")
numbers = []

for number in f:
    numbers.append(int(number.split('\n')[0]))
print("---------------------")

interval = [1000, 5000, 10000, 50000, 100000]
functions = [bubble]

for func in functions:
    for size in interval:
        func(numbers[0:size], size)
    print("---------------------")