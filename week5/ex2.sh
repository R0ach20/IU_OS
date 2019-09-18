for ((i=0; i<1000; i++)); do
	#Lock file during its changing
	if ln file file.lock
	then
		#critical region (CR) if reading and writing to file

		#CR start
		n=`tail -1 file`
		n=$((n+1))
		echo $n >> file
		#CR end
		
		rm file.lock
	else
		#if file was locked retry without incrementing i
		i=$((i-1))
	fi
done