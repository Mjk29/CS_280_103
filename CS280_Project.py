import string


lineInput= "Screen door slams. Mary\'s  \n dress \n waves. Like a     vision she dances \n across the porch as the \n radio     plays."

print(len(lineInput))

# print(lineInput)




# def wordLength(word):




splitList = lineInput.split()

# print(splitList)

# print(splitList[4])

# for word in splitList:
	
	# print(len(word))

i=0
newList=[]

for char in lineInput:
	i +=1
	if char in string.printable:
		newList += char
	if len(newList) ==40:
		print(newList)
		print(len(newList))
		pass

lineString = ''.join(newList)
print(lineString)






# print(string.ascii_letters)

# print(i)

# print (newList)


