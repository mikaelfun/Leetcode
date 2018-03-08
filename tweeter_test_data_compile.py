# Enter your code here. Read input from STDIN. Print output to STDOUT
import collections

firstline = str(input())
startYM = firstline[:7]
endYM = firstline[-7:]
#print ()
#print (startYM)
#print (endYM)
input()
map = {}

elements = []
while True:
    try:
        tm = input()
        if tm == "":
            break
        elements.append(tm)
    except:
        break

for each in elements:
    #print (each)
    ym, form, num = each.strip().split(', ')
    #print (ym)
    #print (form)
    #print (num)
    temp = form+', '+num
    if str(ym[:7]) not in map:
        map[ym[:7]] = {}
        map[ym[:7]][form] = num
    else:
        if form not in map[ym[:7]]:
            map[ym[:7]][form] = num
        else:
            map[ym[:7]][form] = str(int(map[ym[:7]][form]) + int(num))


#print (map)
myMap = {}
for i in map:
    if (i>=startYM and i<endYM):
        myMap[i] = map[i]



#print (myMap)
sortedMap = collections.OrderedDict(sorted(myMap.items(), reverse=True))

#print (sortedMap)

output = {}
oneline = ""
for y in sortedMap:
    sortedTemp = collections.OrderedDict(sorted(sortedMap[y].items()))
    oneline = ""+y+", "
    for z in sortedTemp:
        oneline += z
        oneline += ", "
        oneline += sortedTemp[z]
        oneline += ", "
    oneline = oneline[:-2]
    print (oneline)
# print (myMap)
# print ('end')


