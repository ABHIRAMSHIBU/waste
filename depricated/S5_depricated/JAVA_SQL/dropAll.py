f=open("process.txt","r")
data=f.read()
data=data.split("\n")
f=open("processed.txt","w")
for i in data:
    temp="drop table "
    temp=temp+i
    temp=temp+" cascade constraint;\n"
    f.write(temp)
f.close()

    
