OBJ_FILE="test-2.obj"
loading_address='0x1'
loading_address=int(loading_address,16)
fobj=open(OBJ_FILE,"r")
lines=fobj.read().split("\n")[1:]
print(lines)
starting_address=int(lines[0].split("^")[1],16)
pc=starting_address
m=[]
for i in lines:
    if(i[0]=="T"):
        nextadd=int(i.split("^")[1],16)
        print(pc,nextadd)
        if(nextadd!=pc):
            for k in range(pc,nextadd):
                m.append("00")
                pc+=1
            print("PC=",hex(pc))
        joined="".join(i.split("^")[3:])
        splitted=i.split("^")[4:]
        bit_mask=format(int(i.split("^")[3],16),'b')
        length=int(i.split("^")[2],16)
        for k in range(len(splitted)):
            if(bit_mask[k]=='1'):
                splitted[k]=format(int(splitted[k],16)+loading_address,'x').zfill(6)
        for k in range(len(splitted)):
           splitted[k]= [splitted[k][j:j+2] for j in range(0,len(splitted[k]),2)][::-1]
        print(splitted)
        p=[]
        for j in splitted:
            for k in j:
                p+=[k]
        print("p=",p)
        m+=p
f=open("Memory.txt","w")
for i in range(len(m)):
    f.write(hex(starting_address+i)+"\t\t"+m[i]+"\n")
        
