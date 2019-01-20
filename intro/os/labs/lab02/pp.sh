while read item
do
    read item
    echo item
    arr=($(ls $item))
    for x in $arr
    do
        echo $x
    done
done