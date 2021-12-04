import datetime

def bubble (vector, len):
    start = datetime.datetime.now()

    i = 0
    while (i < len):
        j = 0
        while(j < len - 1 - i):
            if (vector[j + 1] < vector[j]):
                aux = vector[j]
                vector[j] = vector[j + 1]
                vector[j + 1] = aux
            j += 1
        i += 1

    
    finish = datetime.datetime.now()
    time = finish - start
    print(f'Bubble {len} - time: {time.total_seconds() * 1000}')

