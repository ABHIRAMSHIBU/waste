#!/usr/bin/env python3
'''
PG1      START       2000
            LDA         AR
MEH     TD             AR
            JEQ           MEH
            .J               LAST
            RD             AR
            J                MEH
            LDA            AR
AR       WORD        100
'''
asmfn=input("Enter asm:")
with open(asmfn) as asmf:
    #print(asmf)
    oc=[]
    optab={
    "lda":"00",
    "td":"04",
    "jeq":"08",
    "j":"0c",
    "rd":"10",}
    symtab={
    }
    pc=0;
    asmd=asmf.read().lower().split("\n")
    start=True
    stata=0
    textRecord=["T^"+hex(pc).replace("0x","").zfill(6)+"^TXTL",0]
    for line in asmd:
        if(line.strip() in ["","."] ):
            continue
        try:
            label,opcode,operand=[i.strip("[]") for i in ("["+line+"]").split()]
        except:
            print("Not in expected format (hint:no spaces):",line)
        if(start):
            if("start" in opcode ):
                if(operand):
                    objStr="H^"+label+"^"+operand.zfill(6)+"^PGL"
                    pc=int(operand,16)
                else:
                    objStr="H^"+"PG1"+"^"+"0".zfill(6)+"^PGL"
                    pc=0
            else:
                objStr="H^"+"PG1"+"^"+"0".zfill(6)+"^PGL"
                pc=0
            start=False
            print(objStr)
            oc.append(objStr)
            starta=pc
            #print("PC=",hex(pc).strip("0x"))
            textRecord=["T^"+hex(pc).replace("0x","").zfill(6)+"^TXTL",0]
            continue
        if(label):
            symtab[label]=pc
            print("symtab",symtab)
        if("end" in opcode):
            print("Debug:",hex(textRecord[1]).replace("0x","").zfill(2))
            textRecord[0]=textRecord[0].replace("TXTL",hex(textRecord[1]).replace("0x","").zfill(2))
            oc.append(textRecord[0])
            if(operand):
                endr="E^"+hex(symtab[operand]).replace("0x","").zfill(6)
            else:
                endr="E^"+hex(starta).replace("0x","").zfill(6)
            oc.append(endr)
            oc[0]=oc[0].replace("PGL",hex(pc-starta).replace("0x","").zfill(6))
            break
        if( opcode.strip() == "word" ):
            textRecord[0]+="^"+hex(int(operand)).replace("0x","").zfill(6)
            textRecord[1]+=3
            pc+=3
        if( opcode.strip() == "byte"):
            value=operand[2:-1]
            if(operand.strip()[0]=="c"):
                char_value="".join(list(map(str,list(map(ord,value)))))
                textRecord[0]+="^"+char_value
                textRecord[1]+=len(char_value)
                pc+=int(len(value))
            elif(operand.strip()[0]=="x"):
                pc+=math.ceil(len(value)*0.5)
        if(opcode.strip() == "resw"):
            textRecord[0]=textRecord[0].replace("TXTL",hex(textRecord[1]).replace("0x","").zfill(2))
            oc.append(textRecord[0])
            pc+=3*int(operand)
            textRecord=["T^"+hex(pc).strip("0x").zfill(6)+"^TXTL",0]
        if(opcode.strip() == "resb"):
            textRecord[0]=textRecord[0].replace("TXTL",hex(textRecord[1]).replace("0x","").zfill(2))
            oc.append(textRecord[0])
            pc+=int(operand)
            textRecord=["T^"+hex(pc).strip("0x").zfill(6)+"^TXTL",0]
        if( opcode.strip() in optab ):
            code=""
            opcode=optab[opcode]
            if(operand.strip() in symtab):
                code=opcode+hex(symtab[operand]).replace("0x","").zfill(4)
            else:
                #forward to be implemented
                code=opcode+operand
                print("Operand=",operand)
            if(textRecord[1]+3>30):
                print("Debug:",hex(textRecord[1]).replace("0x","").zfill(2))
                textRecord[0]=textRecord[0].replace("TXTL",hex(textRecord[1]).replace("0x","").zfill(2))
                oc.append(textRecord[0])
                textRecord=["T^"+hex(pc).strip("0x").zfill(6)+"^TXTL",0]
            textRecord[0]+="^"+code
            textRecord[1]+=3
            pc+=3
            print("Code=",code)
objstring="\n".join(oc)
for i in symtab:
    if(i in objstring):
        objstring=objstring.replace(i,hex(symtab[i]).replace("0x","").zfill(4))
#obj=objstring.split("\n")
objf=open(asmfn.replace(".asm","")+".obj",'w')
objf.write(objstring)
#[objf.write(i+"\n") for i in oc]
print(objstring)
