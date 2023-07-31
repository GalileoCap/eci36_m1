from random import randint, shuffle

def generate(n = 10, a = 1, b = 10):
  nuts = [str(randint(a, b)) for i in range(n)]
  bolts = nuts.copy()
  shuffle(nuts)

  print(n)
  print(' '.join(bolts))
  print(' '.join(nuts))

generate(100, b = 100)
