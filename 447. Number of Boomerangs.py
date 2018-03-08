import math
class Solution:
    def dist(self, a,b):

        dist = math.pow(abs(a[0] - b[0]),2) + math.pow(abs(a[1] - b[1]),2)
        dist = math.sqrt(dist)
        #print (dist)
        return dist


    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count = 0
        for a in range(0, len(points)):
            # print (a)
            for b in range(a+1, len(points)):
                if b == a:
                    continue
                for c in range(b+1, len(points)):
                    if c == a or c == b:
                        continue
                    l = []
                    l.append(points[a])
                    l.append(points[b])
                    l.append(points[c])
                    # print (l)
                    if (self.dist(self, l[0],l[1]) == self.dist(self, l[1],l[2]) or
                        self.dist(self, l[0],l[2]) == self.dist(self, l[1],l[2]) or
                        self.dist(self, l[0],l[1]) == self.dist(self, l[0],l[2])):
                        print ("dist ", l[0],l[1], " == dist ", l[1],l[2])
                        count+=1

        print (count*2)
        return count*2

if __name__ == "__main__":
    a = Solution
    pts = [[0,1], [3,5], [0,2], [8,5]]
    print (a.dist(a, [0,1], [3,5]))
    a.numberOfBoomerangs(a, pts)

