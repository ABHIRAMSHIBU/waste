function sum(){
	if [ $# -eq 2 ]
	then
		echo $(( $1 + $2 ))
	fi
}
function substract(){
	if [ $# -eq 2 ]
	then
		echo $(( $1 - $2 ))
	fi
}
function multiply(){
	if [ $# -eq 2 ]
	then
		echo $(( $1 * $2 ))
	fi
}
function devide(){
	if [ $# -eq 2 ]
        then
                echo $(( $1 / $2 ))
        fi
}
function exponent(){
	if [ $# -eq 2 ]
        then
		exp=$1
		N=$(( $2 - 1 ))
                while [ ! $N -eq 0 ]
        	do
                	exp=$(( $exp * $2  ))
                	N=$(( N - 1 ))
        	done
		echo $exp
        fi
}


echo $(exponent 2 10)
