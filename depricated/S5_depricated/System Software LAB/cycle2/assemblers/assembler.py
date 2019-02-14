import math
traditionalInterFile="output"
customInterFile="output1"
objectFile="assembled.obj"
PC=0
Name="PG1"
OPTAB={"ADD":{"Opcode":"18"},
       "AND":{"Opcode":"40"},
       "COMP":{"Opcode":"28"},
       "DIV":{"Opcode":"24"},
       "J":{"Opcode":"3C"},
       "JEQ":{"Opcode":"30"},
       "JGT":{"Opcode":"34"},
       "JLT":{"Opcode":"38"},
       "JSUB":{"Opcode":"48"},
       "LDA":{"Opcode":"00"},
       "LDB":{"Opcode":"68"},
       "LDCH":{"Opcode":"50"},
       "LDL":{"Opcode":"08"},
       "LDX":{"Opcode":"04"},
       "LPS":{"Opcode":"D0"},
       "MUL":{"Opcode":"20"},
       "OR":{"Opcode":"44"},
       "RD":{"Opcode":"D8"},
       "RSUB":{"Opcode":"4C"},
       "SSK":{"Opcode":"EC"},
       "STA":{"Opcode":"0C"},
       "STB":{"Opcode":"78"},
       "STCH":{"Opcode":"54"},
       "STI":{"Opcode":"D4"},
       "STL":{"Opcode":"14"},
       "STSW":{"Opcode":"E8"},
       "STX":{"Opcode":"10"},
       "SUB":{"Opcode":"1C"},
       "TD":{"Opcode":"E0"},
       "TIX":{"Opcode":"2C"},
       "WD":{"Opcode":"DC"}}

SYMTAB={}
def RESW(line,PC):
    number=int(line[2])
    PC+=number*3
    return PC
def RESB(line,PC):
    number=int(line[2])
    PC+=number
    return PC
def WORD(line,PC):
    PC+=3
    return PC
def BYTE(line,PC):
    pcOffset=0
    string=line[2]
    operation=string[0]
    string=string.strip("'").strip("X").strip("C").strip("'")
    print("Operation=",operation," Data=",string)
    if(operation=='X'):
        pcOffset=len(string)/2
        if(len(string)%2):
            pcOffset=(len(string)+1)/2
    elif(operation=='C'):
        pcOffset=len(string)
    return int(PC+pcOffset)
PSEUDOOPTAB={
        "RESW":{"Subroutine":RESW},
        "RESB":{"Subroutine":RESB},
        "WORD":{"Subroutine":WORD},
        "BYTE":{"Subroutine":BYTE}
}
def optabLookUp(opcode):
    for i in OPTAB:
        if(i==opcode):
           return OPTAB[i]["Opcode"]
def pseudooptabLookUp(pseudoopcode):
    for i in PSEUDOOPTAB:
        if(i==pseudoopcode):
           return PSEUDOOPTAB[i]["Subroutine"]
def symLookUpAndAdd(symbol,PC):
    for i in SYMTAB:
        if(i==symbol):
            return SYMTAB[i]["Address"]
    SYMTAB[symbol]={"Address":PC}
def symLookUp(symbol):
    for i in SYMTAB:
        if(i==symbol):
            return SYMTAB[i]["Address"]
print(SYMTAB)
def verify():
    count=0
    for i in OPTAB:
        count1=0
        for j in OPTAB:
            if(count==count1):
                continue
            else:
                if(i==j):
                    print("Name conflict:",i,"\t",j)
                else:
                    if(OPTAB[i]["Opcode"] == OPTAB[j]["Opcode"]):
                        print("Opcode conflict:",i,"\t",j)
            count1+=1
        count+=1
     
# 1st PASS
def passOne():
    f=open(input("Enter file name:"))
    data=f.read()
    data=data.split("\n")
    f=open(traditionalInterFile,"w")
    f1=open(customInterFile,"w")
    Name=""
    PC=0
    for i in data:
        test=("]"+i).split()
        test[0]=test[0].replace("]","")
        print(test)
        if(len(test)==1):
            continue
        if('.' in test[0]):
            continue
        if(test[1]=="START" and len(test)>2):
            PC=int("0x"+test[2],0)
            if(test[0]!=""):
                Name=test[0]
        elif(test[1]=="END" and len(test)>=2):
            print("Program END")
            f.write(hex(PC))
            f1.write(hex(PC))
            f.write("\t")
            f1.write("\t")
            for z in range(1,len(test)):
                f.write(test[z])
                if(z==1):
                    f1.write(test[z])
                else:
                    f1.write(test[z])
                f.write("\t")
                f1.write("\t")
            f.write("\n")
            f1.write("\n")
        else:
            if(test[0]!=""):
                symLookUpAndAdd(test[0],PC)
            opcode=optabLookUp(test[1])
            if(opcode==None):
                function=pseudooptabLookUp(test[1])
                if(function != None):
                    f.write(hex(PC))
                    f1.write(hex(PC))
                    f.write("\t")
                    f1.write("\t")
                    for z in range(1,len(test)):
                        f.write(test[z])
                        if(z==1):
                            f1.write(test[z])
                        else:
                            f1.write(test[z])
                        f.write("\t")
                        f1.write("\t")
                    f.write("\n")
                    f1.write("\n")
                    PC=function(test,PC)
            else:
                f.write(hex(PC))
                f1.write(hex(PC))
                f.write("\t")
                f1.write("\t")
                for z in range(1,len(test)):
                    f.write(test[z])
                    if(z==1):
                        f1.write(opcode)
                    else:
                        f1.write(test[z])
                    f.write("\t")
                    f1.write("\t")
                f.write("\n")
                f1.write("\n")
                PC+=3
                print(opcode)
    f.close()
    f1.close()
    if(Name==""):
        Name="PG1"
    return PC,Name
# Write symtab [Just for debugging]
def dumpSymtab():
    f=open("/tmp/symtab","w")
    for i in SYMTAB:
        f.write(i)
        f.write("\t")
        f.write(hex(SYMTAB[i]["Address"]))
        f.write("\n")
    f.close()
def zeroFill(data,length=6):
    if(len(data)<length):
        data="0"*(length-len(data))+data
    return data
def length_textRecord(textRecord,return_hex=True):
    return math.ceil(len("".join(textRecord).replace("^",""))*0.5)
#     if(return_hex):
#         return tr_len
#     else:
#         return int(tr_lex,0)
def closeTextRecord(textRecord,f=None):
    start=textRecord.pop(0)
    print("The length of the text record is "+str(length_textRecord(textRecord)))
#     outputString="T^"+zeroFill(start.replace("0x",""))+"^"+zeroFill(hex(len(textRecord)*3).replace("0x",""),2)
    outputString="T^"+zeroFill(start.replace("0x",""))+"^"+zeroFill(hex(length_textRecord(textRecord)).replace("0x",""),2)
    for i in textRecord:
        outputString+="^"+i
    if(f!=None):
        f.write(outputString+"\n")
    return outputString
def createTextRecord(start):
    return [start]
def insertIntoTextRecord(textRecord,data,PC,f):
    
#     if(len(textRecord)<11):
#         textRecord.append(data)
    if(length_textRecord(textRecord[1:]+[data])<=30):
         textRecord.append(data)
    else:
        closeTextRecord(textRecord,f)
        print("Creating text record with value:",PC)
        textRecord=createTextRecord(PC)
        print("Created text record:",textRecord)
        textRecord.append(data)
    return textRecord
def passTwo():
    print("Start Pass 2")
    f=open(customInterFile,"r")
    data=f.read()
    f.close()
    f=open(objectFile,"w")
    data=data.split("\n")
    start=data[0].split()[0]
    start=zeroFill(start)
    print(data[0].split())
    headRecord="H^"+Name+"^"+zeroFill(start.replace("0x",""))+"^"+zeroFill(hex(PC-int(start,0)).replace("0x",""))
    f.write(headRecord+"\n")
    textRecord=None
    for i in data:
        i=i.split()
#         if(textRecord==None):
#             textRecord=createTextRecord(i[0])
        if(len(i)>1):
            if(i[1]=="RESW" or i[1]=="RESB"):
                if(textRecord != None):
                    closeTextRecord(textRecord,f)
                    textRecord=None
#             elif(i[1]=="WORD"): 
#                 outputString=i[0].strip("0x")
#                 if(len(outputString+hex(i[2]))<6):
#                     offset=6-len(outputString+hex(i[2]))
#                     offsetData="0"*offset
#                     outputString+=offsetData
#                 outputString+=hex(i[2])
#                 if(textRecord==None):
#                     textRecord=createTextRecord(i[0])
#                 insertIntoTextRecord(textRecord,outputString,i[0],f)
            elif(i[1]=="BYTE"):
                try:
                    string=i[2]
                    operation=string[0]
                    string=string.strip("'").strip("X").strip("C").strip("'")
                    print("Operation=",operation," Data=",string)
                    if(operation=='X'):
                        outputData=string
                    elif(operation=='C'):
                        hex_ascii_list=list(map(hex,list(map(ord,string))))
                        outputData="".join([c.strip("0x") for c in hex_ascii_list])
                except:
                    outputData=0
                if(textRecord==None):
                    textRecord=createTextRecord(i[0])
                textRecord=insertIntoTextRecord(textRecord,outputData,i[0],f)
            elif(i[1]=="WORD"):
                try:
                    outputData=int(i[2].strip())
                except:
                    outputData=0
                if(len(hex(outputData).replace("0x",""))<6):
                    outputData = zeroFill(hex(outputData).replace("0x",""))
                if(textRecord==None):
                    textRecord=createTextRecord(i[0])
                textRecord=insertIntoTextRecord(textRecord,outputData,i[0],f)
            elif(i[1]=="END"):
                print("WroteEnd Record")
                if(textRecord != None):
                    closeTextRecord(textRecord,f)
                try:
                    start=hex(symLookUp(i[2])).replace("0x","")
                except:
                    pass
                outputString="E^"+zeroFill(start)
                f.write(outputString+"\n")
            else:
                operand="0000"
                if(len(i)==3):
                    if("," in i[2]):
                        symbol=i[2].split(",")[0].strip()
                        operand=hex(symLookUp(symbol)+int(0x8000)).replace("0x","")
                        print("Unimplemented x but, symbol is:",operand)
                    else:
                        try:
                            operand=hex(symLookUp(i[2])).replace("0x","")
                        except:
                            print("Symbol not found")
                instruction=i[1]+zeroFill(operand,4)
                if(textRecord==None):
                    textRecord=createTextRecord(i[0])
                print(instruction,i[1])
                textRecord=insertIntoTextRecord(textRecord,instruction,i[0],f)
    f.close()
    return data


PC,Name=passOne()
dumpSymtab()
print("PC=",hex(PC))
# Cleanup variables 
data=passTwo()

