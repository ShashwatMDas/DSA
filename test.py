def addingcost(input1, input2, input3):
	sm = 0
	t = 0
	sm1 = 0
	for i in range(0, input1-1, 2):
		print(i)
		t = t+2
		sm1 = sm1+input2[i]
		sm = sm+input3*(input2[i]+input2[i+1])
		i = i+1

	# print(sm1)
	# print(t)
	# if t < input1:
		# sm = sm + (sm1+input2[t])*input3

	return sm

print(addingcost(3, [1, 2, 3], 2))