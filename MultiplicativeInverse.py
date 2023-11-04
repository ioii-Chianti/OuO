# Python3 program to find modular inverse of A under modulo M
# A naive method to find modulor multiplicative inverse of A under modulo M

def MultiplicativeInverse(a, n):
    for x in range(1, n):
        if ((a % n) * (x % n) % n == 1):
            return x
    return -1

if __name__ == "__main__":
    A = 3
    N = 616

    print(f'{A} * {MultiplicativeInverse(A, N)} = 1 (mod {N})')