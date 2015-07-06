stdin = open('input.txt')
n = int(stdin.readline())
Towers = [list(map(int,stdin.readline().split()[1:])) for i in range(n)];
def mpow(x):
    return x[0] if (len(x) == 1) else x[0] ** mpow(x[1:])
CalcTowers = [ (mpow(Towers[i]), i + 1)  for i in range(len(Towers))]
CalcTowers.sort();
CalcTowers = [x[-1] for x in CalcTowers]
for x in CalcTowers:
    print(x, end = ' ')

