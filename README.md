#Análise e Síntese de Algoritmos
Project assignments for the Analysis and Synthesis of Algorithms course for #2 Semester of LEIC, IST@Alameda

Grupo 162 | Francisco Baio (ist17****) e André Silva (ist175455)


##Function to run tests. by [@nuno-silva]
```sh
$ function test { ./main < tests/$1.in > tests/$1.myout; diff tests/$1.myout tests/$1.out; }
$ function run_tests { for f in {01..05}; do test 0$f; done }
```


just run_tests
yey




[@nuno-silva]:https://github.com/nuno-silva
