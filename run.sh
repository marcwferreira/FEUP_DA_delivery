
cmake .. && cmake --build .                                     # compila o sistema
rm -r lines.csv                                                 # remove o ficheiro lines antigo
cp '../data/encomendas.txt' '../data/encomendasCopy.txt'        # cria uma cópia temporária das encomendas

echo "mediaPeso,mediaVolume,desvioPeso,desvioVolume,nCarrosPeso,nCarrosVolume" >> lines.csv     # header do ficheiro csv

for attemp in {1..400}; do                                      # em cada um dos 400 testes
    ./main >> lines.csv                                         # o output do script é escrito no ficheiro
    sed -i '' '$d' '../data/encomendas.txt'                     # elimina uma encomenda
done;

rm -r '../data/encomendas.txt'                                  # elimina o ficheiro "estragado"
mv '../data/encomendasCopy.txt' '../data/encomendas.txt'        # a cópia intacta passa a ser o ficheiro principal