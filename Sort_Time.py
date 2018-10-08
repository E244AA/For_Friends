a = int(input())

b = []
for i in range(a):
  arr = list(map(int, input().split()))
  b.append(arr)

for i in range(a):
  for j in range(a-1):
    if((b[j][0] > b[j+1][0]) or (b[j][0] == b[j+1][0] and b[j][1] > b[j+1][1]) or (b[j][0] == b[j+1][0] and b[j][1] == b[j+1][1] and b[j][2] > b[j+1][2])):
      c = b[j]
      b[j] = b[j+1]
      b[j+1] = c

for i in range(a):
  print(str(b[i][0]) + " " + str(b[i][1]) + " " + str(b[i][2]))
