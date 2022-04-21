for case in {1..3}
do
    echo "--> Case$case:"
    for ((i=2000; i<=40000; i+=2000))  
    do  
        python3 packagesGenerator.py "$i";
        bash case$case.sh "$i"
        rm -r "../../input/encomendas$i.txt";
    done 
done