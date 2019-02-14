PG1      START       2000
            LDA         AR
MEH     TD             AR
            JEQ           MEH
            .J               LAST
            RD             AR
boo     RESW        1000
            J                MEH
            LDA            AR
AR       WORD        49152
            END 
