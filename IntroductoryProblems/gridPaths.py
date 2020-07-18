s = input()


def createGrid(path):
    [x,y] = [0,0]
    grid = [[0 for _ in range(7)] for _ in range(7)]
    grid[x][y] = 1
    for c in path:
        if c=='D':
            x+=1
        elif c=='U':
            x-=1
        elif c=='R':
            y+=1
        elif c=='L':
            y-=1
        if x<0 or x>6 or y<0 or y>6 or grid[x][y]==1:
            return None, None
        else:
            grid[x][y]=1
    return grid,[x,y]

def nextPossibilities(grid, position):
    [x,y]=position
    ps, nn = checkNext(grid,position)
    must = [0 for _ in range(len(ps))]
    imps = [0 for _ in range(len(ps))]

    for i in range(len(ps)):
        num_pss, _ = checkNext(grid,nn[i])
        num_ns = len(num_pss)
        if num_ns==0:
            return None
        elif nn[i]==[6,0]:
            imps[i]=1
        elif num_ns==1:
            must[i]=1
    if sum(must)>1:
        return None
    elif sum(must)==1:
        if sum(imps)==0 or must.index(1)!=imps.index(1):
            ps = [ps[must.index(1)]]
    elif sum(imps)!=0:
#        suma =0
#        for i  in range(7):
#            suma+=sum(grid[i])
#        if suma!=47:
        for i in reversed(range(len(imps))):
            if imps[i]==1:
                ps.remove(ps[i])

    return ps

def checkNext(grid, position):
    [x,y]=position
    ps = ['D', 'U', 'R', 'L']
    nn = []
    res = []
    t = 0
    for i in [x+1,x-1]:
        if i>=0 and i<7 and grid[i][y]==0:
            res.append(ps[t])
            nn.append([i,y])
        t+=1

    for j in [y+1,y-1]:
        if j>=0 and j<7 and grid[x][j]==0:
            res.append(ps[t])
            nn.append([x,j])
        t += 1
    return res,nn

def nicePrint(list,n):
    t = 0
    f = open("/path.txt", 'a+')

    f.write('[')
    while t<len(list):
        text = ""
        for _ in range(n):
            if t==len(list):
                break
            text+=("'"+list[t]+"', ")
            t+=1
        f.write(text)
    f.write(']')
    f.close()

def findPath(s):
    next_paths = [""]
    for i in range(47):
        paths = next_paths

        print(i, len(paths))
        next_paths = []

        for path in paths:
            grid, position = createGrid(path)
            if grid and position:
                ps = nextPossibilities(grid, position)
            if ps:
                if s[i]=='?':
                    for p in ps:
                        next_paths.append(path+p)
                elif ps.count(s[i])==1:
                    next_paths.append(path+s[i])

    paths = next_paths
    next_paths = []

    for path in paths:
        ps = ['D','U','R','L']
        number = [path.count(p) for p in ps]

        if number[0]-number[1]!=6 and number[2]-number[3]!=0:
            continue
        elif number[0]-number[1]==5 and (s[47]=='?' or s[47]=='D'):
            next_paths.append(path+'D')
        elif number[2]-number[3]==1 and (s[47]=='?' or s[47]=='L'):
            next_paths.append(path+'L')

    print(len(next_paths))

findPath(s)