#these two lines i got from stackoverflow
var=$(</dev/stdin) #takes all the lines from input
arr=$(echo $var | tr " " "\n") #im not sure about this line i think it just splits the input by lines and puts them in an array

for x in $arr
do
    #this is needed because ls wont work with just the dir name?
    cd /; cd $x
    
    for y in $(ls)
    do
        #not sure if the exists flag is needed here?
        z=$(readlink -e $y)
        if true
        then
            echo $z
        fi
    done
done


#from slides

#for x in $(ls) #gets the ls as an iterable
#do
    #if x is an executable
#    if [-f $x] && [-x $x]
#        readlink $x
#    fi
#done