import datetime

def insertion (vector, len):
    start = datetime.datetime.now()

    i = 1
    while (i < len):
        aux = vector[i]
        j = i - 1
        while (j >= 0 and vector[j] > aux):
            vector[j + 1] = vector[j]
            j -= 1
        
        vector[j + 1] = aux
        i += 1
    
    finish = datetime.datetime.now()
    time = finish - start
    print(f'Insertion {len} - time: {time.total_seconds() * 1000}')