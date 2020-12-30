S = input()

try:
  total = int(S)*2
  print(total)
except ValueError:
  print("error")

# a = input()
# if a.isdigit():
#   print( int(a,base = 10) *2)
# else:
#   print("error")