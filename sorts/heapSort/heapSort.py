#!/usr/bin/python
def adjustHeap(dataList, beg, end):
	if len(dataList)==0 or beg >=end:
		return
	temp = dataList[beg]
	i = 2 * beg
	while i<=end:
		if i+1<=end and dataList[i]<dataList[i+1]:
			++i
		if(temp >= dataList[i]):
			break
		dataList[beg] = dataList[i]
		beg = i
		i *= 2
	dataList[beg] = temp

def heapSort(dataList, length):
	if len(dataList)==0 or length<=0:
		return
	for i in range(length/2-1, -1, -1):
		adjustHeap(dataList, i, length-1)

	for i in range(length-1, 0, -1):
		dataList[i], dataList[0] = dataList[0], dataList[i]
		adjustHeap(dataList, 0, i-1)

def main():
	data = [1,7, 4, 6, 3, 5, 2]
	print "the original data is:"
	print data
	print "after sorting data is:"
	heapSort(data, 7)
	print data


if __name__ == "__main__":
	main()
	
