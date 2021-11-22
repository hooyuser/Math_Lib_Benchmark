import time
import numpy as np


def main():
    n = 4000
    a = np.random.rand(n, n)
    b = np.random.rand(n, n)

    N = 100
    start = time.perf_counter()
    for i in range(N):
        c = np.dot(a, b)
    end = time.perf_counter()

    print(f"Elapsed time is {(end - start) / N} (s)")  # 0.43413753 (s)


if __name__ == '__main__':
    main()
