import datetime

def selection (vector, len):
    start = datetime.datetime.now()

    i = 0
    while (i < (len - 1)):
        smaller = i
        j = i + 1
        while (j < len):
            if (vector[j] < vector[smaller]):
                smaller = j
            j += 1
        aux = vector[i]
        vector[i] = vector[smaller]
        vector[smaller] = aux
        i += 1

    finish = datetime.datetime.now()
    time = finish - start
    print(f'Selection {len} - time: {time.total_seconds() * 1000}')