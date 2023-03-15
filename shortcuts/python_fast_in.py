import sys
inputs = sys.stdin.read().splitlines()
con = 1
ln = 0
while True:
	a, b = map(int, inputs[ln].split())
	ln += 1
	# a = int(input())
	# b = int(input())
	if a == 0:
		break
	su = 0
	for i in range (a):
		su += int(inputs[ln])
		ln += 1
	print(f"Bill #{con} costs {su}: each friend should pay {su // b}")
	print()
	con += 1