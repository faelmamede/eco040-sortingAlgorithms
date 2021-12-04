import datetime
import math

def shell (vector, len):
    start = datetime.datetime.now()

    h = math.floor(len / 2)
    while (h > 0):
        i = h
        while (i < len):
            aux = vector[i]
            j = i
            while (j >= h and vector[j - h] > aux):
                vector[j] = vector[j - h]
                j -= h
            vector[j] = aux
            i += 1
        h = math.floor(h / 2)
    
    finish = datetime.datetime.now()
    time = finish - start
    print(f'Shell {len} - time: {time.total_seconds() * 1000}')