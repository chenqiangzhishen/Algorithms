#!/usr/bin/python
def adjustHeap(dataList, beg, end):
	if len(dataList)==0 or beg >end:
		return
	temp = dataList[beg]
	i = 2*beg +1
	while i<=end:
		if i+1<=end and dataList[i]<dataList[i+1]:
			i += 1	# note that there no ++i or i++ in the python
		if(temp >= dataList[i]):
			break
		dataList[beg] = dataList[i]
		beg = i
		i = 2*beg +1
	dataList[beg] = temp

def heapSort(dataList):
	if len(dataList)==0:
		return
	for i in range(len(dataList)/2-1, -1, -1):
		adjustHeap(dataList, i, len(dataList)-1)

	for i in range(len(dataList)-1, 0, -1):
		dataList[0], dataList[i] = dataList[i], dataList[0]
		adjustHeap(dataList, 0, i-1)

def main():
	data = [4, 1, 3, 6, 8, 9, 0, 2, 5, 7]
	print "the original data is:"
	print data
	print "after sorting data is:"
	heapSort(data)
	print data


if __name__ == "__main__":
	main()
	
